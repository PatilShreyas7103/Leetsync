class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n = v.size();
        int mx = 0;
        vector<int> f(n,1);
        int cnt = 0;

        vector<int> dp(n,0);
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<i; j++)
            {
                if(v[i]>v[j])
                {
                    if(dp[i]<1+dp[j])
                    {
                        dp[i] = 1+dp[j];
                        f[i] = f[j];
                    }
                    else if(dp[i]==1+dp[j])
                    {
                        f[i]+= f[j];
                    }
                }
            }
            mx = max(mx,dp[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(dp[i]==mx)
            {
                cnt+= f[i];
            }
        }

        return cnt;
    }
};