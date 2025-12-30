class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        int mx = -1;
        int r = -1;
        int c =  -1;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]>mx)
                {
                    mx = v[i][j];
                    r = i;
                    c = j;
                }
            }
        }
        return {r,c};
    }
};