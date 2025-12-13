class Solution {
public:
    int solve(int r, int c, vector<vector<int>> &v, vector<vector<int>> &dp)
    {
        if(r<0 || c<0 || c>r)
        {
            return INT_MAX;
        }

        if(r==0)
        {
            return dp[r][c] = v[0][0];
        }

        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }

        int f1 = solve(r-1,c,v,dp);
        int f2 = solve(r-1,c-1,v,dp);

        return dp[r][c] = v[r][c]+ min(f1,f2);
    }
    int minimumTotal(vector<vector<int>>& v) {
        int m = v.size();

        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int> (m, -1));
        for(int i=0; i<m; i++)
        {
            ans=min(ans, solve(m-1,i,v,dp));
        }

        return ans;
    }
};