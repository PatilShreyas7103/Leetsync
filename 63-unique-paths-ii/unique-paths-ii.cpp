class Solution {
public:

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