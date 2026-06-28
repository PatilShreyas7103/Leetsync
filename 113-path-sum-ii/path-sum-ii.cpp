/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int t, vector<vector<int>> &ans, vector<int> curr)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right)
        {
            t-= root->val;
            curr.push_back(root->val);
            if(t==0)
            {
                ans.push_back(curr);
            }
            curr.pop_back();
            return;
        }
        curr.push_back(root->val);
        solve(root->left,t-root->val,ans,curr);
        solve(root->right,t-root->val,ans,curr);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(root,t,ans,curr);

        return ans;
    }
};