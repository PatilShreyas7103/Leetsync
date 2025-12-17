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
    int solve(int i,int n, string &s, vector<int> &dp)
    {
        if(i==n)
        {
            return  0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans = n;
        for(int j=i; j<n; j++)
        {
            if(palin(i,j,s))
            {
                int cut = 1+ solve(j+1,n,s,dp);
                ans=min(ans, cut);
            }
        }
        return dp[i] =  ans;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp) -1;
    }
};