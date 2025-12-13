class Solution {
public:
    int solve(int i, vector<int> &v, vector<int> &dp)
    {
        if(i==0)
        {
            return dp[i] =  v[0];
        }

        if(i==1)
        {
            return dp[i] =  max(v[0], v[1]);
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int take = v[i]+solve(i-2,v,dp);
        int dont = solve(i-1,v,dp);

        return dp[i] = max(take,dont);
    }
    int rob(vector<int>& v) {
        int n = v.size();

        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return v[0];
        }
        if(n==2)
        {
            return max(v[0], v[1]);
        }
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);

        vector<int> v1,v2;
        for(int i=0; i<n-1; i++)
        {
            v1.push_back(v[i]);
        }
        for(int i=1; i<n; i++)
        {
            v2.push_back(v[i]);
        }

        int ans1 = solve(n-2,v1,dp1);
        int ans2 = solve(n-2,v2,dp2);

        return max(ans1,ans2);
    }
};