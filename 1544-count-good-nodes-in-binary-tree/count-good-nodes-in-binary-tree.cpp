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
    void solve(TreeNode* root, int mx, int &ans)
    {
        if(!root)
        {
            return;
        }

        if(root->val>=mx)
        {
            mx = root->val;
            ans++;
        }
        solve(root->left,mx,ans);
        solve(root->right,mx,ans);
    }
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        int ans = 0;
        solve(root,mx,ans);

        return ans;
    }
};