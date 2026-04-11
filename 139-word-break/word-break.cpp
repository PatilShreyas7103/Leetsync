class Solution {
public:
    bool solve(int i, string s, set<string> &st, int n,
    vector<int> &dp)
    {
        if(i==n)
        {
            return true;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        bool f = false;
        string curr = "";
        for(int j=i; j<n; j++)
        {
            curr+= s[j];
            if(st.find(curr)!=st.end())
            {
                bool c = solve(j+1,s,st,n,dp);
                f = f | c;
            }
        }

        return dp[i] =  f;
    }
    bool wordBreak(string s, vector<string>& v) {
        set<string> st(v.begin(), v.end());
        int n = s.length();
        vector<int> dp(n,-1);

        return solve(0,s,st,n,dp);
    }
};