/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)

        {
            return "";
        }
        string ans = "";
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            if(!node)
            {
                ans+="#,";
            }
            else
            {
                ans+= to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.length()==0)
        {
            return NULL;
        }

        stringstream s(data);
        string str;
        getline(s,str,',');

        queue<TreeNode*> q;
        TreeNode* temp = new TreeNode(stoi(str));
        q.push(temp);
        getline(s,str,',');

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            if(str=="#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode* t = new TreeNode(stoi(str));
                node->left = t;
                q.push(t);
            }
            getline(s,str,',');

            if(str=="#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode* t = new TreeNode(stoi(str));
                node->right = t;
                q.push(t);
            }
            getline(s,str,',');
        }

        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));