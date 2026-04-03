class Solution {
public:
    int solve(int i, int buy, int k, vector<int> &v, int n, vector<vector<vector<int>>> &dp, int mx)
    {
        if(i==n || k==mx)
        {
            return 0;
        }

        if(dp[i][buy][k]!=-1)
        {
            return dp[i][buy][k];
        }

        int dont = solve(i+1,buy,k,v,n,dp,mx);
        int take = INT_MIN;
        if(buy==1)
        {
            take = -v[i]+solve(i+1,0,k,v,n,dp,mx);
        }
        else
        {
            take = v[i]+solve(i+1,1,k+1,v,n,dp,mx);
        }

        return dp[i][buy][k] =  max(dont,take);
    }
    int maxProfit(int k,vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k,-1)));

        return solve(0,1,0,v,n,dp,k);

    }
};