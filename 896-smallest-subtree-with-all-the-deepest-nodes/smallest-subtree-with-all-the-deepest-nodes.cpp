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
    pair<TreeNode*, int> solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return {root, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        int lh = left.second;
        int rh = right.second;

        if(lh>rh)
        {
            return {left.first, lh+1};
        }
        else if(rh>lh)
        {
            return {right.first, rh+1};
        }
        else
        {
            return {root, lh+1};
        }

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).first;
    }
};