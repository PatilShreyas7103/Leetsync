class Solution {
public:

    int change(int t1, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (t1+1,0));
        dp[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int t=0; t<=t1; t++)
            {
                int dont = dp[i-1][t];
                int take = 0;
                if(v[i-1]<=t)
                {
                    take = dp[i][t-v[i-1]];
                }

                dp[i][t] =  (long long)take+dont;
            }
        }

        return dp[n][t1];
    }
};