class Solution {
public:

    int combinationSum4(vector<int>& v, int t1) {
        int n = v.size();
        vector<int> dp(t1+1,0);
        dp[0] = 1;

        for(int t=1; t<=t1; t++)
        {
            int cnt = 0;
            for(auto it: v)
            {
                if(t>=it)
                {
                    cnt+= (long long)dp[t-it];
                }
            }

            dp[t] = cnt;
        }

        return dp[t1];
    }
};