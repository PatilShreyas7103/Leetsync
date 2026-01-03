
class Solution {
public:
    void solve(int i, int n,
               vector<int> &ans,
               set<vector<int>> &res,
               vector<int> &vis,
               vector<int> &v) {

        if (i == n) {
            res.insert(ans);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;

            vis[j] = 1;
            ans.push_back(v[j]);

            solve(i + 1, n, ans, res, vis, v);

            ans.pop_back();
            vis[j] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& v) {
        int n = v.size();
        set<vector<int>> res;
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<vector<int>> p;
        solve(0, n, ans, res, vis, v);
        for(auto vec: res)
        {
            p.push_back(vec);
        }
        return p;
    }
};