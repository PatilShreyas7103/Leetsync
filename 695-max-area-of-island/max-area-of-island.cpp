class Solution {
public:
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }

    void dfs(int row, int col, int m, int n,
    vector<vector<int>> &vis, int &cnt, int dx[], int dy[],
    vector<vector<int>> &v)
    {
        vis[row][col] = 1;
        cnt++;

        for(int i=0; i<4; i++)
        {
            int nr = row+dx[i];
            int nc = col+dy[i];

            if(isValid(nr,nc,m,n))
            {
                if(!vis[nr][nc] && v[nr][nc]==1)
                {
                    dfs(nr,nc,m,n,vis,cnt,dx,dy,v);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int m =  v.size();
        int n = v[0].size();

        vector<vector<int>> vis(m, vector<int> (n,0));
        int maxi = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1 && !vis[i][j])
                {
                    int cnt = 0;
                    dfs(i,j,m,n,vis,cnt,dx,dy,v);
                    maxi = max(maxi, cnt);
                }
            }
        }

        return maxi;
    }
};