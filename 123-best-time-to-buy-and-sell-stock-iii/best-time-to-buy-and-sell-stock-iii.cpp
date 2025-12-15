class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=n-1; i>=0; i--)
        {
            for(int t=2; t>0; t--)
            {
                dp[i][1][t] = max(dp[i+1][1][t], -p[i]+dp[i+1][0][t]);
                dp[i][0][t] = max(dp[i+1][0][t], p[i]+dp[i+1][1][t-1]); 
            }
                   
        }

        return dp[0][1][2];
    }
};