class Solution {
public:
    int solve(int i, string s, int n, vector<int> &dp)
    {
        if(i==n)
        {
            return 1;
        }
        if(s[i]=='0')
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int num = 0;
        int res = 0;
        for(int j=i; j<n; j++)
        {
            num = (long long)num*10 + s[j]-'0';
            if(num>=1 && num<=26)
            {
                res += solve(j+1,s,n,dp);
            }
            else
            {
                break;
            }
        }

        return dp[i] = res;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);

        int ans = solve(0,s,n,dp);

        return ans;
    }
};