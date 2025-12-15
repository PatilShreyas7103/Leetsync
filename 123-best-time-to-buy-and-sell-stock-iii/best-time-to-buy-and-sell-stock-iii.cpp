class Solution {

    int solve(int i, int buy,int t,int n, vector<int>& p, vector<vector<vector<int>>>& dp) {
        if (i == n || t==0) {
            return 0;
        }
        if (dp[i][buy][t] != -1) {
            return dp[i][buy][t];
        }

        if (buy == 1) {
            // we can buy
            return dp[i][buy][t] = max(0 + solve(i + 1, 1,t, n, p, dp),
                                    -p[i] + solve(i + 1, 0,t, n, p, dp));
        } else {
            // we can sell
            return dp[i][buy][t] = max(0 + solve(i + 1, 0,t, n, p, dp),
                                    p[i] + solve(i + 1, 1,t-1, n, p, dp));
        }
    }

public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0,1,2,n,p,dp);
    }
};