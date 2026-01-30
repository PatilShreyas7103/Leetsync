// Summary Ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        vector<string> ans;
        int n = v.size();
        if (n == 0) return ans;

        int l = 0;

        for (int r = 0; r < n; r++) {
            // check if range breaks
            if (r + 1 == n || v[r + 1] != v[r] + 1) {
                if (l == r) {
                    ans.push_back(to_string(v[r]));
                } else {
                    ans.push_back(to_string(v[l]) + "->" + to_string(v[r]));
                }
                l = r + 1;
            }
        }

        return ans;
    }
};
