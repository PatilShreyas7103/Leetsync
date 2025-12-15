class Solution {
public:
    int solve(int i, int j, string a, string b,
    vector<vector<int>> &dp)
    {
        if(i<0)
        {
            return j+1;
        }
        if(j<0)
        {
            return i+1;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(a[i]==b[j])
        {
            return dp[i][j] =  solve(i-1,j-1,a,b,dp);
        }
        else
        {
            int ins = solve(i,j-1,a,b,dp);
            int del = solve(i-1,j,a,b,dp);
            int rep = solve(i-1,j-1,a,b,dp);
            return dp[i][j] =  1+ min(ins,min(del,rep));
        }
    }
    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();

        vector<vector<int>> dp(m, vector<int> (n,-1));

        return solve(m-1,n-1,a,b,dp);
    }
};