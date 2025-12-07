class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        int V = n;
        vector<vector<int>> dist(n, vector<int> (n,1e8));
        for(auto it: edges)
        {
            int from = it[0];
            int to  = it[1];
            int w = it[2];

            dist[from][to] = w;
            dist[to][from] = w;
        }

        for (int k = 0; k < V; k++) {

            for (int i = 0; i < V; i++) {

                for (int j = 0; j < V; j++) {
                    dist[j][j] = 0;
                    if(dist[i][k] != 1e8 && dist[k][j]!= 1e8)
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = -1;
        int mx = INT_MAX;
        for(int i=0; i<n; i++)
        {
            int c = 0;
            for(int j=0; j<n;j++)
            {
                if(dist[i][j]<=k)
                {
                    c++;
                }
            }
            if(c<=mx)
            {
                mx = c;
                ans=i;
            }
        }

        return ans;
    }
};