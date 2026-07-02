class Solution {
public:
    bool solve(int node, vector<vector<int>> &adj,
     vector<int> &col, int c)
     {
        col[node] = c;

        for(auto it: adj[node])
        {
            if(col[it]==-1)
            {
                // not yet 
                bool check = solve(it,adj,col,!c);
                if(!check)
                {
                    return false;
                }
            }
            else
            {
                // already coloured
                if(c==col[it])
                {
                    return false;
                }
            }
        }

        return true;
     }

    bool isBipartite(vector<vector<int>>& v) {
        int n = v.size();

        vector<int> col(n,-1);

        for(int i=0; i<n; i++)
        {
            if(col[i]==-1)
            {
                // not visited
                bool check = solve(i,v,col,0);
                if(!check)
                {
                    return false;
                }
            }
        }

        return true;
    }
};