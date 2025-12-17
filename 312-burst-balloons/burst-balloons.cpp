class Solution {
public:
    int solve(int i, int j, vector<int> &v, vector<vector<int>> &dp)
    {
        if(i>j)
        {
            return dp[i][j] =  0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k=i; k<=j; k++)
        {
            int cut = v[i-1]*v[k]*v[j+1] + solve(i,k-1,v,dp) + solve(k+1,j,v,dp);
            ans=max(ans, cut);
        }

        return dp[i][j] =  ans;
    }
    int maxCoins(vector<int>& v) {
        // int n = v.size();
        v.push_back(1);
        v.insert(v.begin(), 1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));

        return solve(1,n-2,v,dp);
    }
};