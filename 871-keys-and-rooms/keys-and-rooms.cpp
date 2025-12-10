class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& v) {
        queue<int> q;
        q.push(0);
        int n = v.size();

        vector<int> vis(n,0);
        vis[0] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: v[node])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

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