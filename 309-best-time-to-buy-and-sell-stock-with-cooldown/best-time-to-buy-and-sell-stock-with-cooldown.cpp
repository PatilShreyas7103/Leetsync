class Solution {
public:

    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+2, vector<int> (2,0));

        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=1; j++)
            {
                int dont = dp[i+1][j];
                int take = INT_MIN;

                if(j==1)
                {
                    take = -v[i]+dp[i+1][0];
                }
                else
                {
                    take = v[i]+dp[i+2][1];
                }

                dp[i][j] = max(dont,take);
            }
        }

        return dp[0][1];

    }
};