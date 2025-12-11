
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
    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        int n = v.size();

        DisJointSet ds(n+1);
        vector<int> ans;

        for(auto it: v)
        {

            int a = it[0];
            int b = it[1];

            if(ds.FindUpar(a)==ds.FindUpar(b))
            {
                ans = it;
                break;
            }
            else
            {
                ds.UnionBySize(a,b);
            }
        }

        return ans;
    }
};