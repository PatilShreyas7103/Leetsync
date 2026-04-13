class Solution {
public:
    int solve(int t, vector<int> &v, vector<int> &dp)
    {
        if(t==0)
        {
            return 1;
        }

        if(dp[t]!=-1)
        {
            return dp[t];
        }

        int cnt =0 ;
        for(auto it: v)
        {
            if(t>=it)
            {
                cnt+= solve(t-it,v,dp);
            }
        }

        return dp[t] =  cnt;

    }
    int combinationSum4(vector<int>& v, int t) {
        int n = v.size();
        vector<int> dp(t+1,-1);

        return solve(t,v,dp);
    }
};