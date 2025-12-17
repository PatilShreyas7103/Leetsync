class Solution {
public:


    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--)
        {
            int mx = 0;
            int len = 0;
            int ans = 0;

            for(int j=i; j<min(i+k,n); j++)
            {
                len++;
                mx = max(mx, v[j]);
                int key = mx*len + dp[j+1];
                ans=max(ans, key);
            }
            dp[i] = ans;
        }

        return dp[0];
    }
};