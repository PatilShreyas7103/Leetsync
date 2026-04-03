class Solution {
public:

    int maxProfit(int k1,vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k1+1,0)));

        for(int i=n-1; i>=0 ;i--)
        {
            for(int j=0; j<=1; j++)
            {
                for(int k=0; k<k1; k++)
                {
                    int dont = dp[i+1][j][k];
                    int take = INT_MIN;
                    if(j==1)
                    {
                        take = -v[i]+dp[i+1][0][k];
                    }
                    else
                    {
                        take = v[i]+dp[i+1][1][k+1];
                    }

                    dp[i][j][k] =  max(dont,take);
                }
            }
        }

        return dp[0][1][0];

    }
};