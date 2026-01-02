class Solution {
public:
    void solve(int idx, vector<int>& v,
               vector<int>& ans, vector<vector<int>>& res) {

        res.push_back(ans);

        for (int i = idx; i < v.size(); i++) {
            // skip duplicates at the same recursion level
            if (i > idx && v[i] == v[i - 1]) {
                continue;
            }

            ans.push_back(v[i]);
            solve(i + 1, v, ans, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());

        vector<vector<int>> res;
        vector<int> ans;
        solve(0, v, ans, res);
        return res;
    }
};