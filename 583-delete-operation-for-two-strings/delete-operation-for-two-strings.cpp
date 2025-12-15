class Solution {
public:
    int solve(string p, string q, int i, int j, 
    vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(p[i]==q[j])
        {
            // can take
            return dp[i][j] = 1+solve(p,q,i-1,j-1,dp);
        }
        else
        {
            return dp[i][j] = max(solve(p,q,i-1,j,dp), solve(p,q,i,j-1,dp));
        }
    }
    int minDistance(string p, string q) {
        int m = p.length();
        int n = q.length();

        vector<vector<int>> dp(m, vector<int> (n,-1));
        return (m+n) - 2*solve(p,q,m-1,n-1,dp);
    }
};