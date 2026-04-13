class Solution {
public:
    int solve(int i, vector<int> &v, int n, vector<int> &dp)
    {
        if(i>=n)
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int one = solve(i+1,v,n,dp);
        int take = solve(i+2,v,n,dp);

        return dp[i] =  min(one,take)+v[i];
    }
    int minCostClimbingStairs(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n,-1);

        return min(solve(0,v,n,dp), solve(1,v,n,dp));
    }
};