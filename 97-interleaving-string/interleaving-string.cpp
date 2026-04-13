
class Solution {
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        if(i == s1.length() && j == s2.length())
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        int k = i + j;

        bool ans = false;

        if(i < s1.length() && s1[i] == s3[k])
            ans = ans || solve(i + 1, j, s1, s2, s3, dp);

        if(j < s2.length() && s2[j] == s3[k])
            ans = ans || solve(i, j + 1, s1, s2, s3, dp);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.length();
        int y = s2.length();

        if(x + y != s3.length()) return false;

        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));

        return solve(0, 0, s1, s2, s3, dp);
    }
};