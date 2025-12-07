class Solution {
public:
    int networkDelayTime(vector<vector<int>>& v, int n, int k)  {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto it: v)
        {
            int a = it[0];
            int b = it[1];
            int cost = it[2];

            adj[a].push_back({b,cost});
        }

        int d = 0;
        vector<int> dis(n+1,INT_MAX);
        dis[k] = 0;
        queue<int> q;
        q.push(k);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: adj[node])
            {
                int adnode = it.first;
                int w = it.second;

                if(dis[node]+w<dis[adnode])
                {
                    dis[adnode] = w+dis[node];
                    q.push(adnode);
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(dis[i]==INT_MAX)
            {
                return -1;
            }
            ans=max(ans,dis[i]);
        }

        return ans;
    }
};