
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.length();
        int y = s2.length();

        if(x + y != s3.length()) return false;

        vector<vector<bool>> dp(x+1, vector<bool>(y+1, false));

        dp[0][0] = true;

        for(int i = 0; i <= x; i++) {
            for(int j = 0; j <= y; j++) {

                if(i > 0 && s1[i-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];

                if(j > 0 && s2[j-1] == s3[i+j-1])
                    dp[i][j] = dp[i][j] || dp[i][j-1];
            }
        }

        return dp[x][y];
    }
};