class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<int> par(n,0);
        vector<int> dp(n,1);
        int maxid = 0;
        int mx = -1;
        for(int i=0;i<n; i++)
        {
            par[i] = i;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(v[i]%v[j]==0 || v[j]%v[i]==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        par[i] = j;
                        dp[i] = 1+dp[j];
                    }
                }
            }
            if(dp[i]>mx)
            {
                maxid = i;
                mx = dp[i];
            }
        }
        
        int id = maxid;
        vector<int> ans;
        
        while(par[id]!=id)
        {
            ans.push_back(v[id]);
            id = par[id];
        }
        ans.push_back(v[id]);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};