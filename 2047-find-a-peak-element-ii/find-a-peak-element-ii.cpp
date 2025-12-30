class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            // Find the max element in the current middle column
            int maxRow = 0;
            for (int i = 1; i < m; ++i) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool leftIsGreater = (mid > 0 && mat[maxRow][mid - 1] > mat[maxRow][mid]);
            bool rightIsGreater = (mid < n - 1 && mat[maxRow][mid + 1] > mat[maxRow][mid]);

            if (!leftIsGreater && !rightIsGreater) {
                return {maxRow, mid}; // Found a peak
            } else if (leftIsGreater) {
                right = mid - 1; // Move to the left half
            } else {
                left = mid + 1; // Move to the right half
            }
        }

        return {-1, -1}; // Should not reach here for a valid input
    }
};
