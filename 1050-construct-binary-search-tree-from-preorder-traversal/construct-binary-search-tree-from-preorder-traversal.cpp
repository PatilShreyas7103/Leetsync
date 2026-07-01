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
    TreeNode* solve(vector<int> &p, int &id, int n, int mn, int mx)
    {
        if(id>=n)
        {
            return NULL;
        }

        if(p[id]<mn || p[id]>mx)
        {
            return NULL;
        }

        TreeNode* temp = new TreeNode(p[id]);
        id++;
        temp->left = solve(p,id,n,mn,temp->val-1);
        temp->right = solve(p,id,n,temp->val+1,mx);

        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        int id = 0;
        int n = p.size();
        int mx = INT_MAX;
        int mn = INT_MIN;

        return solve(p,id,n,mn,mx);
    }
};