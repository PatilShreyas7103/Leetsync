class Solution {
public:
    int m, n;

    int solve(int r, int c1, int c2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)
            return -1e9;

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int cherries = grid[r][c1];
        if (c1 != c2)
            cherries += grid[r][c2];

        if (r == m - 1)
            return dp[r][c1][c2] = cherries;

        int maxi = 0;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                maxi = max(maxi,
                           solve(r + 1, c1 + i, c2 + j, grid, dp));
            }
        }

        return dp[r][c1][c2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1))
        );

        return solve(0, 0, n - 1, grid, dp);
    }
};