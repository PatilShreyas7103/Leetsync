class Solution {
public:
    bool isValid(int r,int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }

    void gameOfLife(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> ans(m, vector<int> (n,0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==1)
                {
                    // live cell
                    int cnt = -1;
                    for(int a=-1; a<=1; a++)
                    {
                        for(int b=-1; b<=1; b++)
                        {
                            int r = i+a;
                            int c = j+b;
                        
                            if(isValid(r,c,m,n))
                            {
                                if(v[r][c]==1)
                                {
                                    cnt++;
                                }
                            }
                        }
                    }
                    if(cnt<2)
                    {
                        ans[i][j] = 0;
                    }
                    else if(cnt>3)
                    {   
                        ans[i][j] = 0;
                    }
                    else
                    {
                        // lives
                        ans[i][j] = 1;
                    }
                }
                else
                {
                    int cnt = 0;
                    // dead cell
                    for(int a=-1; a<=1; a++)
                    {
                        for(int b=-1; b<=1; b++)
                        {
                            int r = i+a;
                            int c = j+b;
                            
                            if(isValid(r,c,m,n))
                            {
                                if(v[r][c]==1)
                                {
                                    cnt++;
                                }
                            }
                        }
                    }
                    if(cnt==3)
                    {
                        ans[i][j] = 1;
                    }
                    else
                    {
                        ans[i][j] = 0;
                    }
                }
            }
        }
        v = ans;
    }
};