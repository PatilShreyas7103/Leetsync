class Solution {
public:
    int solve(int i, int n,int k, vector<int> &v,
    vector<int> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int ans = INT_MIN;
        int mx = -1;
        for(int j=i; j<min(n,i+k); j++)
        {
            mx=max(mx,v[j]);
            int t = mx*(j-i+1) + solve(j+1,n,k,v,dp);
            ans=max(ans,t);
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n,-1);
        return solve(0,n,k,v,dp);
    }
};