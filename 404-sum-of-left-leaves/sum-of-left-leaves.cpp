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
    void solve(TreeNode* root, int &ans, bool valid)
    {
        if(!root)
        {
            return ;
        }

        if(!root->left && !root->right)
        {
            if(valid)
            {
                ans+=root->val;
                return;
            }
        }

        solve(root->left,ans,1);
        solve(root->right,ans,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        solve(root,ans,0);

        return ans;
    }
};