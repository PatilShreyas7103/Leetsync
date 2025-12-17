class Solution {
public:
    int minCost(int n, vector<int>& v) {
        v.push_back(n);
        v.insert(v.begin(), 0);
        sort(v.begin(), v.end());
        int m = v.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 2; i >= 1; i--) {
            for (int j = i; j <= m - 2; j++) {
                int ans = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = v[j + 1] - v[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    ans = min(ans, cost);
                }
                dp[i][j] = ans;
            }
        }

        return dp[1][m - 2];
    }
};
