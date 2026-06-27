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
    void search (TreeNode* root, int st, TreeNode* &temp)
    {
        if(!root)
        {
            return;
        }

        if(root->val==st)
        {
            temp = root;
            return;
        }

        search(root->left,st,temp);
        search(root->right,st,temp);
    }

    void solve(TreeNode* root, map<TreeNode*, TreeNode*> &mp)
    {
        if(root==NULL)
        {
            return;
        }

        solve(root->left,mp);
        solve(root->right,mp);
        if(root->left)
        {
            mp[root->left] = root;
        }
        if(root->right)
        {
            mp[root->right] = root;
        }
    }

    int amountOfTime(TreeNode* root, int st) {
        TreeNode* temp = NULL;
        search(root,st,temp);

        map<TreeNode*, TreeNode*> mp;
        solve(root, mp);
        vector<int> vis(1e5+1,0);
        int k = 0;
        
        queue<TreeNode*> q;
        q.push(temp);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto node = q.front();
                q.pop();
                vis[node->val]=1;
                if(node->left && !vis[node->left->val])
                {
                    q.push(node->left);
                }
                if(node->right && !vis[node->right->val])
                {
                    q.push(node->right);
                }
                if(mp.find(node)!=mp.end() && !vis[mp[node]->val])
                {
                    q.push(mp[node]);
                }
            }
            k++;
        }

        return k-1;

    }
};