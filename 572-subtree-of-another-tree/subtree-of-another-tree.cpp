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
    bool solve(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        {
            return 1;
        }

        if(!p || !q)
        {
            return 0;
        }
        bool l = solve(p->left,q->left);
        bool r = solve(p->right,q->right);

        return l && r && p->val==q->val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
        {
            return false;
        }

        if(solve(root,subRoot))
        {
            return true;
        }

        bool l = isSubtree(root->left,subRoot);
        bool r = isSubtree(root->right,subRoot);

        return l || r;
    }
};