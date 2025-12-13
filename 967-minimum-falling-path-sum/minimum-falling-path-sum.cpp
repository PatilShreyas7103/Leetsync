class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int> (n,INT_MAX));

        for(int i=0; i<n; i++)
        {
            dp[0][i] = v[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int f1 = dp[i-1][j];
                int f2 = INT_MAX;
                if(j<n-1)
                {
                    f2 = dp[i-1][j+1];
                }
                int f3 = INT_MAX;
                if(j>0)
                {
                    f3 = dp[i-1][j-1];
                }
                dp[i][j] = v[i][j]+min({f1,f2,f3});
            }
        }

        for(int i=0; i<n; i++)
        {
            ans=min(ans, dp[n-1][i]);
        }

        return ans;
    }
};