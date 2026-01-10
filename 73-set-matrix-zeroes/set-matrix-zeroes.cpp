class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        unordered_set<int> row;
        unordered_set<int> col;
        int m = v.size();
        int n = v[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto r: row)
        {
            for(int i=0; i<n; i++)
            {
                v[r][i] = 0;
            }
        }
        for(auto c: col)
        {
            for(int i=0; i<m; i++)
            {
                v[i][c] = 0;
            }
        }

        
    }
};