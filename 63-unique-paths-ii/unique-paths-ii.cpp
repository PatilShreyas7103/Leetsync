class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(i==0 && j==0)
        {
            return dp[i][j] = 1;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int up = solve(i-1,j,v,dp);
        if(i>0 && v[i-1][j]==1)
        {
            up = 0;
        }

        int left = solve(i,j-1,v,dp);
        if(j>0 && v[i][j-1]==1)
        {
            left = 0;
        }

        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        if(v[0][0]==1 || v[m-1][n-1]==1)
        {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int> (n,0));
        for(int i=0; i<m; i++)
        {
            if(v[i][0]==1)
            {
                break;
            }
            dp[i][0] = 1;
        }
        for(int i=0; i<n; i++)
        {
            if(v[0][i]==1)
            {
                break;
            }
            dp[0][i] = 1;
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                int up = dp[i-1][j];
                int left = dp[i][j-1];

                if(v[i][j]==1)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j] = up+left;
                }
                
            }
        }


        return dp[m-1][n-1];
    }
};