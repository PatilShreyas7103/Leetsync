class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        if(n==1)
        {
            return 0;
        }

        int ans = 0;
        int buy = v[0];

        for(int i=1; i<n; i++)
        {
            ans=max(ans,v[i]-buy);
            buy = min(buy,v[i]);
        }

        return ans;
    }
};