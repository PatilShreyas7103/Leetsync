/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int solve(Node* root, int &ans)
    {
        if(!root)
        {
            return 0;
        }
        int curr = 0;
        auto c = root->children;
        for(auto node: c)
        {
            curr = max(curr,solve(node,ans));
        }
        ans=max(ans,curr+1);

        return curr+1;

    }
    int maxDepth(Node* root) {
        int ans = 0;
        int h =  solve(root,ans);

        return ans;
    }
};