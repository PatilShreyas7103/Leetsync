class Solution {
public:
    int solve(int i, int buy, vector<int> &v, int n,
    vector<vector<int>> &dp, int fee)
    {
        if(i==n)
        {
            return 0;
        }

        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }

        int dont = solve(i+1,buy,v,n,dp,fee);
        int take = INT_MIN;

        if(buy==1)
        {
             take = -v[i]+solve(i+1,0,v,n,dp,fee);
        }
        else
        {
            // sell
             take = -fee+v[i]+solve(i+1,1,v,n,dp,fee);
        }
        return dp[i][buy] =  max(take,dont);
    }

    int maxProfit(vector<int>& v, int fee) {

        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));

        return solve(0,1,v,n,dp,fee);

    }
};