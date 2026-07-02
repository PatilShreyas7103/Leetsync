class Solution {
public:
    bool isValid(int r, int c,int m, int n)
    {
        return (r<m && c<n && r>=0 && c>=0);
    }

    void solve(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        queue<pair<int,int>> q;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        vector<vector<int>> vis(m, vector<int> (n,0));

        for(int i=0;i<m; i++)
        {
            if(v[i][0]=='O')
            {
                vis[i][0] = 1;
                q.push({i,0});
            }
            if(v[i][n-1]=='O')
            {
                vis[i][n-1] = 1;
                q.push({i,n-1});
            }
        }

        for(int i=0;i<n; i++)
        {
            if(v[0][i]=='O')
            {
                vis[0][i] = 1;
                q.push({0,i});
            }
            if(v[m-1][i]=='O')
            {
                vis[m-1][i] = 1;
                q.push({m-1,i});
            }
        }

        while(!q.empty())
        {
            auto cor = q.front();
            q.pop();

            int r = cor.first;
            int c = cor.second;

            for(int i=0; i<4; i++)
            {
                int adjr = r+dr[i];
                int adjc = c+dc[i];

                if(isValid(adjr,adjc,m,n))
                {
                    if(v[adjr][adjc]=='O' && !vis[adjr][adjc])
                    {
                        q.push({adjr,adjc});
                        vis[adjr][adjc] = 1;
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]=='O' && !vis[i][j])
                {
                    v[i][j] = 'X';
                }
            }
        }
    }
};