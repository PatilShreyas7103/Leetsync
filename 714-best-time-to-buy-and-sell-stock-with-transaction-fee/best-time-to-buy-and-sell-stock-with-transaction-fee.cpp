class Solution {
public:

    int maxProfit(vector<int>& v, int f) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
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
                    dp[i][j] = max(dp[i+1][j], v[i]-f+dp[i+1][!j]);
                }
            }
        }

        return dp[0][1];
    }
};