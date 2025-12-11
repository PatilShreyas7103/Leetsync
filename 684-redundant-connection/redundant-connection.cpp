class Solution {
public:
    void solve(int node, vector<int> adj[], int &count,
    vector<int> &vis)
    {
        vis[node] = 1;
        // count++;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                count++;
                solve(it,adj,count,vis);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        vector<int> ans;
        int n = v.size();
        // sort(v.begin(), v.end());
        vector<int> adj[n+1];
        int prev = 1;

        for(auto it: v)
        {
            int r = it[0];
            int c = it[1];

            adj[r].push_back(c);
            adj[c].push_back(r);

            int count = 0;
            vector<int> vis(n+1,0);
            // solve(1,adj,count,vis);
            for(int i=1; i<=n; i++)
            {
                if(!vis[i])
                {
                    solve(i,adj,count,vis);
                }
            }

            if(count==prev)
            {
                ans = it;
            }
            
            prev = count;
            
        }

        return ans;
    }
};