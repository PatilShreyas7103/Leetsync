class Solution {
public:

    int longestCommonSubsequence(string p, string q) {
        int m = p.length();
        int n = q.length();

        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(p[i-1]==q[j-1])
                {
                    // take
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};