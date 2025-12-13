class Solution {
public:
    int solve(int i, vector<int> &v, vector<int> &dp)
    {
        if(i==0)
        {
            return v[0];
        }

        if(i==1)
        {
            return max(v[0], v[1]);
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int take = v[i]+solve(i-2,v,dp);
        int notTake = solve(i-1,v,dp);

        return dp[i] =  max(take,notTake);
    }
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n,-1);

        return solve(n-1,v,dp);
    }
};