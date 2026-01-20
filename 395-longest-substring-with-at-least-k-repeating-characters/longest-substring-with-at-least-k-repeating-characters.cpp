class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                bool valid = true;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0 && freq[c] < k) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};