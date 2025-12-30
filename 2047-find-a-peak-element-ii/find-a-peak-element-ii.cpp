class Solution {
public:
    bool isValid(int r, int c, int m, int n)
    {
        return (r>=0 && c>=0 && r<m && c<n);
    }
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                bool f = true;
                for(int k=0; k<4; k++)
                {
                    int adjr = i+dx[k];
                    int adjc = j+dy[k];

                    if(isValid(adjr,adjc,m,n))
                    {
                        int adval = v[adjr][adjc];
                        int val = v[i][j];

                        if(adval>val)
                        {
                            f = false;
                            break;
                        }
                    }
                }
                if(f)
                {
                    return {i,j};
                }
            }
        }


        return {-1,-1};
    }
};