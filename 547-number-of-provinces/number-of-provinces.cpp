class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;

        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> adj[n+1];

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        int ans = 0;
        vector<int> vis(n+1,0);
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};