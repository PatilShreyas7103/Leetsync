// Longest Increasing Subsequence - Tabulation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();

        // dp[i][pre+1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // i goes from n-1 to 0
        for (int i = n - 1; i >= 0; i--) {
            // pre goes from i-1 to -1
            for (int pre = i - 1; pre >= -1; pre--) {

                // option 1: skip current element
                int notTake = dp[i + 1][pre + 1];

                // option 2: take current element (if valid)
                int take = 0;
                if (pre == -1 || v[i] > v[pre]) {
                    take = 1 + dp[i + 1][i + 1];
                }

                dp[i][pre + 1] = max(take, notTake);
            }
        }

        return dp[0][0]; // i = 0, pre = -1
    }
};