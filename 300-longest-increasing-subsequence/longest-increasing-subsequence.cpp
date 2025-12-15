class Solution {
public:
    int solve(int i, int pre, vector<int> &v, int n, vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][pre+1]!=-1)
        {
            return dp[i][pre+1];
        }

        int dont = solve(i+1,pre,v,n,dp);
        int take = 0;
        if(pre==-1 || v[i]>v[pre])
        {
            take = 1+solve(i+1,i,v,n,dp);
        }

        return dp[i][pre+1]= max(take,dont);
    }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));

        return solve(0,-1,v,n,dp);
    }
};