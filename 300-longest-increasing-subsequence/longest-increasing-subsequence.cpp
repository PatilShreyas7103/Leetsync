class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n,1);
        int mx = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(v[j]<v[i])
                {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};