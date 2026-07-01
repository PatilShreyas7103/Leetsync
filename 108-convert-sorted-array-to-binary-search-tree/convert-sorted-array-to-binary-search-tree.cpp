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
    TreeNode* solve(int s, int e, vector<int> &v)
    {
        if(s>e)
        {
            return NULL;
        }

        int mid = (s+e)/2;
        TreeNode* temp = new TreeNode(v[mid]);
        temp->left = solve(s,mid-1,v);
        temp->right = solve(mid+1,e,v);

        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n = v.size();

        return solve(0,n-1,v);
    }
};