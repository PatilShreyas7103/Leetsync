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
    TreeNode* prev;
    TreeNode* f1;
    TreeNode* f2;

    void solve(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        solve(root->left);
        if(prev)
        {
            if(prev->val>root->val)
            {
                if(!f1)
                {
                    f1 = prev;
                }
                f2 = root;
            }
            
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);

        swap(f1->val,f2->val);
    }
};