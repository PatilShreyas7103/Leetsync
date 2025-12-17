class Solution {
public:
    bool palin(int i, int j, string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);

        for(int i=n-1; i>=0; i--)
        {
            int ans = n;
            for(int j=i; j<n; j++)
            {
                if(palin(i,j,s))
                {
                    int cut = 1+ dp[j+1];
                    ans=min(ans, cut);
                }
            }
            dp[i] =  ans;
        }

        return dp[0]-1;
        
    }
};