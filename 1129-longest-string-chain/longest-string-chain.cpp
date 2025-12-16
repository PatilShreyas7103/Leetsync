class Solution {
public:
    bool validate(const string &s, const string &t) {
        if (s.length() + 1 != t.length()) return false;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; j++;
            } else {
                j++;
            }
            if (j - i > 1) return false;
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        vector<int> dp(n, 1);
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (validate(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};
