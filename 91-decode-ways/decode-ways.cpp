class Solution {
public:

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n] = 1;

        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='0')
            {
                dp[i] = 0;
            }
            else
            {
                int num = 0;
                int res = 0;
                for(int j=i; j<n; j++)
                {
                    num = (long long)num*10 + s[j]-'0';
                    if(num>=1 && num<=26)
                    {
                        res += dp[j+1];
                    }
                    else
                    {
                        break;
                    }
                }

                dp[i] = res;
            }
        }

        return dp[0];
    }
};