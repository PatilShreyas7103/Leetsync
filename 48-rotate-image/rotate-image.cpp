class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                swap(v[i][j], v[j][i]);
            }
        }

        for(auto &row: v)
        {
            reverse(row.begin(), row.end());
        }
    }
};