class Solution {
public:

    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n,0);

        if(n==1)
        {
            return v[0];
        }

        dp[0] = v[0];
        dp[1] = max(v[0],v[1]);

        for(int i=2; i<n; i++)
        {
            int take = v[i]+dp[i-2];
            int dont = dp[i-1];

            dp[i] = max(take,dont);
        }

        return dp[n-1];
    }
};