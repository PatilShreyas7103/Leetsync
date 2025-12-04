class Solution {
public:
    bool isValid(int i, int j, int m, int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }

    void dfs(int r, int c, int m, int n, vector<vector<char>>& v, vector<vector<int>> &vis, int dr[], int dc[])
    {
        vis[r][c] = 1;

        for(int i=0; i<4; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(isValid(nr,nc,m,n))
            {
                if(!vis[nr][nc] && v[nr][nc]=='O')
                {
                    dfs(nr,nc,m,n,v,vis,dr,dc);
                }
            }
        }
    }

    void solve(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    if(v[i][j]=='O')
                    {
                        dfs(i,j,m,n,v,vis,dr,dc);
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vis[i][j]==0)
                {
                    v[i][j] = 'X';
                }
            }
        }
    }
};