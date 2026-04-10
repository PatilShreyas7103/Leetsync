class Solution {
public:

    int maxCoins(vector<int>& v) {
        v.push_back(1);
        v.insert(v.begin(), 1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n,0));

        for(int i=n-2; i>=1; i--)
        {
            for(int j=i; j<=n-2; j++)
            {
                int ans = INT_MIN;
                for(int k=i; k<=j; k++)
                {
                    int cut = v[i-1]*v[k]*v[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans=max(ans, cut);
                }
                dp[i][j] = ans;
            }
        }

        return dp[1][n-2];
    }
};