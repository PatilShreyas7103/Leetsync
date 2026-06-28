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
    int stats(TreeNode* root)
    {
        if(root->left && root->right)
        {
            return 2;
        }
        else if(!root->left && !root->right)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    TreeNode* solve(TreeNode* root, int key)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->val==key)
        {
            int child = stats(root);

            if(child==0)
            {
                return NULL;
            }
            else if(child==1)
            {
                if(root->left)
                {
                    return root->left;
                }
                else
                {
                    return root->right;
                }
            }
            else
            {
                TreeNode* t = root->right;
                while(t->left)
                {
                    t = t->left;
                }
                root->val = t->val;
                root->right = solve(root->right,t->val);
                return root;
            }
        }
        else if(key<root->val)
        {
            root->left = solve(root->left,key);
        }
        else
        {
            root->right = solve(root->right,key);
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }

        return solve(root, key);
    }
};