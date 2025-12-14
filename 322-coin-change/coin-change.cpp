class Solution {
public:
    int solve(int i, int t, vector<int> &c, 
    vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(t%c[0])
            {
                return dp[i][t] = 1e8;
            }
            else
            {
                return dp[i][t] = t/c[0];
            }
        }

        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }

        int dont = solve(i-1,t,c,dp);
        int take = 1e8;
        if(t>=c[i])
        {
            take = 1+solve(i,t-c[i],c,dp);
        }

        return dp[i][t] = min(take,dont);
    }
    
    int coinChange(vector<int>& v, int t) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (t+1,-1));

        int ans = solve(n-1,t,v,dp);
        if(ans==1e8)
        {
            return -1;
        }
        return ans;
    }
};