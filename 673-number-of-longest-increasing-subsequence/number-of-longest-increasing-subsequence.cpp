class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n = v.size();
        vector<pair<int,int>> dp(n, {1,1});
        int mx = 0;

        for(int i=0;i<n; i++)
        {
            for(int j=0; j<i; j++){
                if(v[j]<v[i])
                {
                    if(1+dp[j].first==dp[i].first)
                    {
                        dp[i].second+= dp[j].second;
                    }
                    else if(1+dp[j].first>dp[i].first)
                    {
                        dp[i].second = dp[j].second;
                        dp[i].first=1+dp[j].first;
                    }
                }
            }
            if(dp[i].first>mx)
            {
                mx = dp[i].first;
            }
        }
        int ans  = 0;
        for(auto it: dp)
        {
            if(it.first==mx)
            {
                ans+= it.second;
            }
        }

        return ans;
    }
};