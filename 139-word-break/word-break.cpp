class Solution {
public:
    bool wordBreak(string s, vector<string>& v) {
        set<string> st(v.begin(), v.end());
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n] = 1;

        for(int i=n-1; i>=0; i--)
        {
            bool f = false;
            string curr = "";
            for(int j=i; j<n; j++)
            {
                curr+= s[j];
                if(st.find(curr)!=st.end())
                {
                    bool c = dp[j+1];
                    f = f | c;
                }
            }

            dp[i] =  f;
        }

        return dp[0];
    }
};