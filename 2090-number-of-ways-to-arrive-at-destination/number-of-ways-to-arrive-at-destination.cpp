#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& r) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : r) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<pair<long long, long long>> dis(n, {1e18, 0});  // {distance, count}
        
        dis[0] = {0, 1};  // Start node: Distance = 0, Ways = 1
        pq.push({0, 0});

        long long MOD = 1e9 + 7;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dis[node].first) continue;  // Ignore outdated distances

            for (auto& [adN, wt] : adj[node]) {
                long long newDist = d + wt;

                if (newDist < dis[adN].first) {
                    dis[adN] = {newDist, dis[node].second};
                    pq.push({newDist, adN});
                }
                else if (newDist == dis[adN].first) {
                    dis[adN].second = (dis[adN].second + dis[node].second) % MOD;
                }
            }
        }

        return dis[n - 1].second % MOD;
    }
};
