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
    TreeNode* solve(vector<int> &v, int s, int e)
    {
        if(s>e)
        {
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode* temp = new TreeNode(v[mid]);
        temp->left = solve(v,s,mid-1);
        temp->right = solve(v,mid+1,e);

        return temp;
    }
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(!root)
        {
            return;
        }

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        return solve(v,0,n-1);
    }
};