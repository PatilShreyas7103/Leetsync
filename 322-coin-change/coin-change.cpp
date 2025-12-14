class Solution {
public:
    int solve(int i, int t, vector<int> &c, vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(t%c[i]==0)
            {
                return dp[i][t] =  t/c[i];
            }
            else
            {
                return 1e8;
            }
        }

        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }

        int notTake = 0 + solve(i-1, t,c,dp);
        int take = 1e8;
        if(c[i]<=t)
        {
            take = 1+solve(i,t-c[i],c,dp);
        }

        return dp[i][t] = min(take, notTake);
    }
    int coinChange(vector<int>& c, int t) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int> (t+1, -1));
        int ans = solve(n-1,t,c,dp);
        if(ans==1e8)
        {
            return -1;
        }
        return ans;
    }
};