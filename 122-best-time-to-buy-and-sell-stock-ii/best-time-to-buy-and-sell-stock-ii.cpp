class Solution {
public:
    int solve(int i, int buy, vector<int> &v, int n,
    vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }

        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }

        if(buy)
        {
            return dp[i][buy] = max(solve(i+1,buy,v,n,dp), -v[i]+solve(i+1,!buy,v,n,dp));
        }
        else
        {
            return dp[i][buy] = max(solve(i+1,buy,v,n,dp), v[i]+solve(i+1,!buy,v,n,dp));
        }
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(0,1,v,n,dp);
    }
};