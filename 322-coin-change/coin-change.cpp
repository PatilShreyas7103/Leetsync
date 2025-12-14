class Solution {
public:
    int solve(int i, int t, vector<int> &c, 
    vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(t%c[0])
            {
                return dp[i][t] = 1e8;
            }
            else
            {
                return dp[i][t] = t/c[0];
            }
        }

        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }

        int dont = solve(i-1,t,c,dp);
        int take = 1e8;
        if(t>=c[i])
        {
            take = 1+solve(i,t-c[i],c,dp);
        }

        return dp[i][t] = min(take,dont);
    }
    
    int coinChange(vector<int>& c, int t) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int> (t+1,1e8));

        for(int i=0; i<=t; i++)
        {
            if(i%c[0])
            {
                dp[0][i] = 1e8;
            }
            else
            {
                dp[0][i] = i/c[0];
            }
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=t; j++)
            {
                int dont = dp[i-1][j];
                int take = 1e8;
                if(j>=c[i])
                {
                    take = 1+dp[i][j-c[i]];
                }

                dp[i][j] = min(take,dont);
            }
        }

        if(dp[n-1][t]==1e8)
        {
            return -1;
        }
        return dp[n-1][t];
    }
};