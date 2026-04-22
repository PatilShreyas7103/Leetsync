class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)indeg[i]+=matrix[i][j];
        }
        return indeg;
    }
};