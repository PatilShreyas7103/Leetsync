class Solution {
public:
    int solve(int i, int pre, vector<int> &v, int n, 
    vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }

        if(dp[i][pre+1]!=-1)
        {
            return dp[i][pre+1];
        }

        if(pre==-1 || v[i]>v[pre])
        {
            return dp[i][pre+1] = max(solve(i+1,pre,v,n,dp), 1+solve(i+1,i,v,n,dp));
        }
        else
        {
            return dp[i][pre+1]= solve(i+1,pre,v,n,dp);
        }
    }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(0,-1,v,n,dp);
    }
};