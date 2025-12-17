class Solution {
public:
    int solve(int i, int n, vector<int> &v, int k, vector<int> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int mx = 0;
        int len = 0;
        int ans = 0;

        for(int j=i; j<min(i+k,n); j++)
        {
            len++;
            mx = max(mx, v[j]);
            int key = mx*len + solve(j+1,n,v,k,dp);
            ans=max(ans, key);
        }

        return dp[i] =  ans;
    }

    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n, -1);
        return solve(0,n,v,k,dp);
    }
};