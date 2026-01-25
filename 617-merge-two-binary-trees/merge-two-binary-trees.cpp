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
    TreeNode* solve(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            return NULL;
        }

        if(p && !q)
        {
            TreeNode* temp = new TreeNode(p->val);
            temp->left = solve(p->left,q);
            temp->right = solve(p->right,q);
            return temp;
        }

        if(q && !p)
        {
            TreeNode* temp = new TreeNode(q->val);
            temp->left = solve(p,q->left);
            temp->right = solve(p,q->right);
            return temp;
        }

        TreeNode* temp = new TreeNode(p->val+q->val);
        temp->left = solve(p->left,q->left);
        temp->right = solve(p->right,q->right);

        return temp;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1,root2);
    }
};