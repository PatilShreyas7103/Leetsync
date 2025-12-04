class Solution {
public:
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        vector<vector<int>> dis(m, vector<int> (n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==0)
                {
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty())
        {
            auto f = q.front();
            q.pop();

            int r = f.first;
            int c = f.second;

            for(int i=0; i<4; i++)
            {
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(isValid(nr,nc,m,n) && v[nr][nc]==1)
                {
                    if(1+dis[r][c]<dis[nr][nc])
                    {
                        dis[nr][nc] = 1+dis[r][c];
                        q.push({nr,nc});
                    }
                }
            }
        }

        return dis;
    }
};