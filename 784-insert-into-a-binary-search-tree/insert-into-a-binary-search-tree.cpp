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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        TreeNode* prev = NULL;
        TreeNode* curr = root;

        if(!root)
        {
            return new TreeNode(x);
        }

        while(curr)
        {
            if(x<curr->val)
            {
                prev = curr;
                curr = curr->left;
            }
            else
            {
                prev = curr;
                curr = curr->right;
            }
        }

        if(x<prev->val)
        {
            prev->left = new TreeNode(x);
        }
        else
        {
            prev->right = new TreeNode(x);
        }

        return root;
    }
};