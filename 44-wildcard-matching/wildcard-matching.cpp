class Solution {
public:
    bool solve (int i, int j, string &s, string &p)
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

        if(p[j]=='*')
        {
            bool op1 = solve(i-1,j-1,s,p);
            bool op2 = solve(i,j-1,s,p);
            bool op3 = solve(i-1,j,s,p);

            return op1 || op2 || op3;
        }
        else if(p[j]=='?')
        {
            return solve(i-1,j-1,s,p);
        }
        else
        {
            if(s[i]!=p[j])
            {
                return false;
            }
            else
            {
                return solve(i-1,j-1,s,p);
            }
        }
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        bool f = true;
        for(int j=0; j<=n; j++)
        {
            
            dp[0][j] = f;
            if(p[j]!='*')
            {
                f = false;
            }
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(p[j-1]=='*')
                {
                    bool op1 = dp[i-1][j-1];
                    bool op2 = dp[i-1][j];
                    bool op3 = dp[i][j-1];

                    dp[i][j] =  op1 || op2 || op3;
                }
                else if(p[j-1]=='?')
                {
                    dp[i][j] =  dp[i-1][j-1];
                }
                else
                {
                    if(s[i-1]!=p[j-1])
                    {
                        dp[i][j] =  false;
                    }
                    else
                    {
                        dp[i][j] =  dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};