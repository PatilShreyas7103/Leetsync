class Solution {
public:
    int solve(int l, int r, vector<int> &v,int sum,
    vector<vector<int>> &dp)
    {
        if(l>r)
        {
            return 0;
        }

        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }

        int even = (r-l)%2==0;
        int left = even ? v[l] : 0;
        int right = even ? v[r] : 0;

        return dp[l][r] = max(left+solve(l+1,r,v,sum,dp), right+solve(l,r-1,v,sum,dp));
    }
    bool stoneGame(vector<int>& v) {
        int n = v.size();
        int sum = accumulate(v.begin(),v.end(),0);
        vector<vector<int>> dp(n, vector<int> (n,-1));
        int alice = solve(0,n-1,v,sum,dp);
        return alice > (sum-alice);
    }
};