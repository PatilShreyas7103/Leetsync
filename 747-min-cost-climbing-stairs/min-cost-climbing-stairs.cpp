class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n+2,0);

        for(int i=n-1; i>=0; i--)
        {
            int one = dp[i+1];
            int take = dp[i+2];

            dp[i] =  min(one,take)+v[i];
        }

        return min(dp[0], dp[1]);
    }
};