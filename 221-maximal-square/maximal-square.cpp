class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<char>>& matrix) {
        if (i >= rows || j >= cols) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, matrix);
        int down = solve(i + 1, j, matrix);
        int diag = solve(i + 1, j + 1, matrix);

        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min({right, down, diag});
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        rows = matrix.size();
        cols = matrix[0].size();
        dp.assign(rows, vector<int>(cols, -1));

        int max_side = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                max_side = max(max_side, solve(i, j, matrix));
            }
        }

        return max_side * max_side;
    }
};