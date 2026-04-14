class Solution {
public:
    int solve(int i, int t, vector<int> &v, 
    vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return t==0;
        }
        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }

        int dont = solve(i-1,t,v,dp);
        int take = 0;
        if(v[i]<=t)
        {
            take = solve(i,t-v[i],v,dp);
        }

        return dp[i][t] =  take+dont;
    }
    int change(int t1, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (t1+1,0));
        dp[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int t=0; t<=t1; t++)
            {
                int dont = dp[i-1][t];
                int take = 0;
                if(v[i-1]<=t)
                {
                    take = dp[i][t-v[i-1]];
                }

                dp[i][t] =  (long long)take+dont;
            }
        }

        return dp[n][t1];
    }
};