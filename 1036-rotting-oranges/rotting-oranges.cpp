class Solution {
public:
    bool isValid(int m, int n, int i, int j)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int orangesRotting(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> vis(m, vector<int> (n,0));

        queue<pair<int,int>> q;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==2)
                {
                    // rotten
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        int ans = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int sz = q.size();
            // ans++;
            for(int i=0; i<sz; i++)
            {
                auto f = q.front();
                q.pop();

                int r = f.first;
                int c = f.second;

                for(int i=0; i<4; i++)
                {
                    int x = r+dx[i];
                    int y = c+dy[i];

                    if(isValid(m,n,x,y) && !vis[x][y] && v[x][y]==1)
                    {
                        vis[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty())
            {
                ans++;
            }
        }


        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1 && !vis[i][j])
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};