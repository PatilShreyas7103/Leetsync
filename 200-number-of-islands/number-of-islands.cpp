class Solution {
public:
    bool isValid(int i, int j, int m, int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    void dfs(int r, int c, int m, int n, vector<vector<int>> &vis, vector<vector<char>>& v, 
    int dr[], int dc[])
    {
        vis[r][c] = 1;

        for(int i=0; i<4; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(isValid(nr,nc,m,n))
            {
                if(v[nr][nc]=='1' && !vis[nr][nc])
                {
                    dfs(nr,nc,m,n,vis,v,dr,dc);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        int cnt = 0;

        for(int i=0;i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j] && v[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,m,n,vis,v,dr,dc);
                }
            }
        }

        return cnt;
    }
};