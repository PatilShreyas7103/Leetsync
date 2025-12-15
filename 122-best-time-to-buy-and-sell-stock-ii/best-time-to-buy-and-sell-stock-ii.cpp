class Solution {
public:
    int solve(int i, int b, vector<int> &v, int n, vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }

        if(dp[i][b]!=-1)
        {
            return dp[i][b];
        }

        if(b==1)
        {
            return dp[i][b] =  max(solve(i+1,b,v,n,dp), -v[i]+solve(i+1,!b,v,n,dp));
        }
        else
        {
            return dp[i][b] = max(solve(i+1,b,v,n,dp), v[i]+solve(i+1,!b,v,n,dp));
        }
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        // return solve(0,1,v,n,dp);
        for(int i=n-1; i>=0; i--)
        {
            for(int j=1; j>=0; j--)
            {
                if(j==1)
                {
                    // buy
                    dp[i][j] = max(dp[i+1][j], -v[i]+dp[i+1][!j]);
                }   
                else
                {
                    // sell
                    dp[i][j] = max(dp[i+1][j], v[i]+dp[i+1][!j]);
                }
            }
        }

        return dp[0][1];
    }
};