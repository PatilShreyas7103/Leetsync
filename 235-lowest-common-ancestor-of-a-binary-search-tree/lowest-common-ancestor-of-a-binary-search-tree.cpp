/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
        {
            return NULL;
        }
        int x1 = p->val;
        int x2 = q->val;
        int x = root->val;

        if(x<x1 && x<x2)
        {
            return solve(root->right,p,q);
        }
        else if(x>x1 && x>x2)
        {
            return solve(root->left,p,q);
        }
        else
        {
            return root;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};