class Solution {
public:
    void solve(int n, vector<int> &v, vector<int> ans, set<vector<int>> &st) {
        if (n < 0) {
            st.insert(ans);
            return;
        }

        // exclude current element
        solve(n - 1, v, ans, st);

        // include current element
        ans.push_back(v[n]);
        solve(n - 1, v, ans, st);
        ans.pop_back();

    }

    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        set<vector<int>> st;
        vector<int> ans;
        solve(v.size() - 1, v, ans, st);
        for(auto vec: st)
        {
            res.push_back(vec);
        }
        return res;
    }
};