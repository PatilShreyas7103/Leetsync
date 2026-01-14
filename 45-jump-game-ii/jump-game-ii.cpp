class Solution {
public:
    int solve(int i, vector<int> &v, int n, vector<int> &dp)
    {
        if(i==n-1)
        {
            return dp[i] = 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int start = i+1;
        int end = min(n-1,i+v[i]);
        long long ans = INT_MAX;
        for(int j=start;j<=end; j++)
        {
            long long res = (long long)1+solve(j,v,n,dp);
            ans=min(ans,res);
        }

        return dp[i] = ans;
    }
    int jump(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n+1,0);

        for(int i=n-2; i>=0; i--)
        {
            int start = i+1;
            int end = min(n-1,i+v[i]);
            long long ans = INT_MAX;
            for(int j=start;j<=end; j++)
            {
                long long res = (long long)1+dp[j];
                ans=min(ans,res);
            }
            dp[i] = ans;
        }

        return dp[0];
    }
};