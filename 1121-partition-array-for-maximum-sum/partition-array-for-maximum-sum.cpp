class Solution {
public:


    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n+1,0);

        for(int i=n-1; i>=0; i--)
        {
            int ans = INT_MIN;
            int mx = -1;
            for(int j=i; j<min(n,i+k); j++)
            {
                mx=max(mx,v[j]);
                int t = mx*(j-i+1) + dp[j+1];
                ans=max(ans,t);
            }

            dp[i] = ans;
        }
        return dp[0];
    }
};