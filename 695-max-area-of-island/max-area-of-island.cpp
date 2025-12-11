class DisJointSet
{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = FindUpar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }
        if (rank[uu] < rank[uv])
        {
            parent[uu] = uv;
        }
        else if (rank[uu] > rank[uv])
        {
            parent[uv] = uu;
        }
        else
        {
            parent[uv] = uu;
            rank[uu]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }

        if (size[uu] < size[uv])
        {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else
        {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};

class Solution {
public:
    bool isValid(int r, int c, int m, int n) {
        return r >= 0 && c >= 0 && r < m && c < n;
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        DisJointSet ds(m*n);
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int ans = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int node = i*n + j;
                if(v[i][j]==1)
                {
                    for(int k=0; k<4; k++)
                    {
                        int nr = i+dx[k];
                        int nc = j+dy[k];

                        int adnode = nr*n + nc;

                        if(isValid(nr,nc,m,n) && v[nr][nc]==1)
                        {
                            if(ds.FindUpar(node) != ds.FindUpar(adnode))
                            {
                                ds.UnionBySize(node,adnode);
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1)
                {
                    int node = i*n+j;
                    ans=max(ans,ds.size[node]);
                }
            }
        }

        return ans;
    }
};