class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size(), n = v[0].size();
        int s = 0, e = m * n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int row = mid / n;
            int col = mid % n;
            int val = v[row][col];

            if (val == t) return true;
            else if (val < t) s = mid + 1;
            else e = mid - 1;
        }
        return false;
    }
};