class Solution {
public:

    bool solve(int i, int t, vector<int> &v, 
    vector<vector<int>> &dp)
    {
        if(i<0 || t<0)
        {
            return false;
        }
        if(t==0)
        {
            return dp[i][t] = true;
        }
        
        if(i==0)
        {
            return dp[i][t] = t==v[0];
        }
        
        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }
        
        int dont = solve(i-1,t,v,dp);
        int take = false;
        if(t-v[i]>=0)
        {
            take = solve(i-1,t-v[i],v,dp);
        }
        
        return dp[i][t] = dont || take;
        
    }


    bool canPartition(vector<int>& v) {
        int sum = 0;
        for(auto it: v)
        {
            sum+=it;
        }
        if(sum&1)
        {
            return false;
        }

        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (sum/2+1,-1));
        return solve(n-1,sum/2,v,dp);
    }
};