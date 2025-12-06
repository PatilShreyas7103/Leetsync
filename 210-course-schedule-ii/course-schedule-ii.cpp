class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
            indeg[u]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int nb : adj[node]) {
                if (--indeg[nb] == 0) q.push(nb);
            }
        }
        return ans;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> topo = topoSort(n, edges);
        vector<int> ans;
        return topo.size() != (n) ? ans : topo;
    }
};