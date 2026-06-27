/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*, TreeNode*> mp;
        solve(root, mp);
        vector<int> vis(501,0);
        
        queue<TreeNode*> q;
        q.push(target);
        while(k)
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
            k--;
        }


        while(!q.empty())
        {
            
            auto f = q.front();
            q.pop();
            ans.push_back(f->val);
        }

        return ans;
    }
};