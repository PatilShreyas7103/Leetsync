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
    void f1(TreeNode* root, vector<TreeNode*> &v)
    {
        if(!root)
        {
            return;
        }

        f1(root->left,v);
        v.push_back(root);
        f1(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        f1(root,v);
        int n = v.size();

        TreeNode* s = NULL;
        TreeNode* e = NULL;
        for(int i=0; i<n-1; i++)
        {
            int v1 = v[i]->val;
            int v2 = v[i+1]->val;
            if(v2<v1)
            {
                if(s==NULL)
                {
                    s = v[i];
                }
                e = v[i+1];
            }
        }

        swap(s->val,e->val);
    }
};