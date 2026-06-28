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
    void solve(TreeNode* root, long long t, long long &ans)
    {
        if(!root)
        {
            return;
        }
        t-= (long long)root->val;
        ans+= t==0;

        solve(root->left,t,ans);
        solve(root->right,t,ans);
    }
    void eval(TreeNode* root, long long t, long long &res)
    {
        if(!root)
        {
            return;
        }
        long long ans = 0;
        solve(root,t,ans);
        res+= ans;
        eval(root->left,t,res);
        eval(root->right,t,res);
    }

    int pathSum(TreeNode* root, int t) {
        long long res = 0;
        eval(root,t,res);


        return res;
    }
};