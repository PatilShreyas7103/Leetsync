class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> ans(n, vector<int> (m,0));

        for(int i=0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                int d = v[i][j];
                ans[j][i] = d;
            }
        }

        return ans;
    }
};