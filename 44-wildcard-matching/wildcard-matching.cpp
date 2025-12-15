class Solution {
public:
    bool isMatch(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++)
        {
            dp[i][0] = false;
        }
        bool f = true;
        for(int j=1; j<=m; j++)
        {
            if(t[j-1]!='*')
            {
                f = false;
            }
            dp[0][j] = f;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m;  j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    if(t[j-1]=='?')
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(t[j-1]=='*')
                    {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[n][m];
    }
};