class Solution {
public:
    int solve(int i, int prev, vector<int> &v, int n,
    vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }

        
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        

        int dont = solve(i+1,prev,v,n,dp);
        int take = 0;
        if(prev==-1)
        {
            take = 1+solve(i+1,i,v,n,dp);
        }
        else
        {
            if(v[i]>v[prev])
            { 
                // valid
                take = 1+solve(i+1,i,v,n,dp);
            }
        }

        return dp[i][prev+1] =  max(take,dont);
    }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return solve(0,-1,v,n,dp);
    }
};