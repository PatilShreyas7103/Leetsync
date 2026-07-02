class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> adj[n];
        vector<int> in(n,0);
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            for(auto it: v[i])
            {
                // i->it
                adj[it].push_back(i);
                in[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};