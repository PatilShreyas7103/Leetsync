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
 class node
{
    public:
    int mx;
    int mn;
    int count;
    
    node()
    {
        
    }
    
    void assign(int a, int b, int c)
    {
        this->mx = a;
        this->mn = b;
        this->count = c;
    }
    
};

class Solution {
public:
    node* solve(TreeNode* root, int &ans)
    {
        if(!root)
        {
            node* temp = new node();
            temp->assign(INT_MIN,INT_MAX,0);
            return temp;
        }
        
        node* l = solve(root->left,ans);
        node* r = solve(root->right,ans);
        
        int lmn = l->mn;
        int lmx = l->mx;
        int rmn = r->mn;
        int rmx = r->mx;
        
        if(root->val>lmx && root->val<rmn)
        {
            // valid one
            int tot = l->count+r->count+root->val;
            ans=max(ans,tot);
            
            int mxx = max({root->val,lmx,rmx});
            int mnn = min({root->val,lmn,rmn});
            node* temp = new node();
            temp->assign(mxx,mnn,tot);
            
            return temp;
        }
        else
        {
            node* temp = new node();
            temp->assign(INT_MAX,INT_MIN,0);
            
            return temp;
        }
    }
    

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        
        auto k = solve(root,ans);
        return ans;
    }
};