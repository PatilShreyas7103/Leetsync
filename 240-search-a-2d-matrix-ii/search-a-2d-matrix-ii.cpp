class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size();
        int n = v[0].size();

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0) {
            if (v[i][j] == t) {
                return true;
            } else if (v[i][j] > t) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};