class Solution {
public:

    int minimumTotal(vector<vector<int>>& v) {
        int m = v.size();

        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int> (m, INT_MAX));

        dp[0][0] = v[0][0];
        for(int i=1; i<m; i++)
        {
            dp[i][0] = dp[i-1][0]+v[i][0];
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<=i; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1])+v[i][j];
            }
        }

        for(int i=0; i<m; i++)
        {
            ans=min(ans, dp[m-1][i]);
        }

        return ans;
    }
};