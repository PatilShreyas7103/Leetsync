class Solution {
    private:
    int dfs(int i, string& s, unordered_set<string>& words, vector<int>& dp) {
        int n = s.length();
        if(i==n)
        {
            return dp[i] = 0;
        }
        if (dp[i] != -1) return dp[i];
        int res = 1 + dfs(i + 1, s, words, dp);
        for (int j = i; j < s.size(); j++) {
            if (words.count(s.substr(i, j - i + 1))) {
                res = min(res, dfs(j + 1, s, words, dp));
            }
        }
        dp[i] = res;
        return res;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return dfs(0, s, words, dp);
    }
};