class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return INT_MAX;
        }

        if(i==0 && j==0)
        {
            return dp[i][j] = v[0][0];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int up = solve(i-1,j,v,dp);
        int left = solve(i,j-1,v,dp);

        return dp[i][j] =  v[i][j]+ min(up, left);
    }
    int minPathSum(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();

        vector<vector<int>> dp(m, vector<int> (n,-1));

        return solve(m-1,n-1,v,dp);
    }
};