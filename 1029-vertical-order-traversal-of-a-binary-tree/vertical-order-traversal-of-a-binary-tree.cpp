
class Solution {
public:
    void solve(TreeNode* root, int row, int col, vector<pair<pair<int,int>,int>> &v) {
        if (root == NULL) return;

        v.push_back({{col, row}, root->val});
        solve(root->left, row + 1, col - 1, v);
        solve(root->right, row + 1, col + 1, v);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<pair<int,int>, int>> v;
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        solve(root, 0, 0, v);
        sort(v.begin(), v.end());

        map<int, vector<int>> mp;
        for (auto &it : v) {
            int col = it.first.first;
            int val = it.second;
            mp[col].push_back(val);
        }

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};