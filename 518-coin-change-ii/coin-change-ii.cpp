class Solution {
public:
    int solve(int i, int t, vector<int> &v, 
    vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return t==0;
        }
        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }

        int dont = solve(i-1,t,v,dp);
        int take = 0;
        if(v[i]<=t)
        {
            take = solve(i,t-v[i],v,dp);
        }

        return dp[i][t] =  take+dont;
    }
    int change(int t, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (t+1,-1));

        return solve(n-1,t,v,dp);

    }
};