class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }

private:
    int solve(string &s, int start, int end, int k) {
        if (end - start < k) return 0;

        vector<int> freq(26, 0);
        for (int i = start; i < end; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = start; i < end; i++) {
            if (freq[s[i] - 'a'] < k) {
                int left = solve(s, start, i, k);
                int right = solve(s, i + 1, end, k);
                return max(left, right);
            }
        }

        // All characters have frequency >= k
        return end - start;
    }
};