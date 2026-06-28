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
    TreeNode* solve(vector<int> &p, vector<int> &in, int ps, int pe, map<int,int> &id,int is, int ie)
    {
        if(ps>pe || is>ie)
        {
            return NULL;
        }

        TreeNode* temp = new TreeNode(p[pe]);
        int x = id[p[pe]];
        int rightnodes = ie-id[p[pe]];
        
        temp->right = solve(p,in,pe-rightnodes,pe-1,id,x+1,ie);
        temp->left = solve(p,in,ps,pe-rightnodes-1,id,is,x-1);

        return temp;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        int n = in.size();
        map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[in[i]] = i;
        }

        return solve(p,in,0,n-1,mp,0,n-1);
    }
};