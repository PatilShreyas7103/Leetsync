class Solution {
public:
    void dfs(int node, vector<int> &vis,
    vector<vector<int>>& adj)
    {
        vis[node] = 1;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> vis(n,0);
        dfs(0,vis,adj);

        for(auto it: vis)
        {
            if(it==0)
            {
                return false;
            }
        }

        return true;
    }
};