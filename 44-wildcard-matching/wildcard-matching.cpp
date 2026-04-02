class Solution {
public:
    bool solve (int i, int j, string &s, string &p,
    vector<vector<int>> &dp)
    {
        if(i<0)
        {
            // string done
            for(int id=0; id<=j; id++)
            {
                if(p[id]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(j<0)
        {
            return false;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(p[j]=='*')
        {
            bool op1 = solve(i-1,j-1,s,p,dp);
            bool op2 = solve(i,j-1,s,p,dp);
            bool op3 = solve(i-1,j,s,p,dp);

            return dp[i][j] =  op1 || op2 || op3;
        }
        else if(p[j]=='?')
        {
            return dp[i][j] =  solve(i-1,j-1,s,p,dp);
        }
        else
        {
            if(s[i]!=p[j])
            {
                return dp[i][j] =  false;
            }
            else
            {
                return dp[i][j] =  solve(i-1,j-1,s,p,dp);
            }
        }
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solve(m-1,n-1,s,p,dp);
    }
};