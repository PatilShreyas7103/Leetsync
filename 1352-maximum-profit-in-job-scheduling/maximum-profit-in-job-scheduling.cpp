class Solution {
public:
    int jobScheduling(vector<int>& a, vector<int>& b, vector<int>& p) {
        int n = a.size();

        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({a[i], b[i], p[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n + 1, 0); // dp[n] = 0

        for (int i = n - 1; i >= 0; i--) {

            // find next compatible job
            int lo = i + 1, hi = n - 1, next = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (jobs[mid][0] >= jobs[i][1]) {
                    next = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            int take = jobs[i][2] + dp[next];
            int dont = dp[i + 1];

            dp[i] = max(take, dont);
        }

        return dp[0];
    }
};