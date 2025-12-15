class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        if(n==1)
        {
            return 0;
        }

        vector<int> mn(n,INT_MAX);
        vector<int> mx(n,INT_MIN);
        int k = INT_MAX;

        for(int i=0; i<n; i++)
        {
            k = min(k,v[i]);
            mn[i] = k;
        }
        k = INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            mx[i] = k;
            k = max(k,v[i]);
        }
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            ans=max(ans,mx[i]-mn[i]);
        }

        return ans;
    }
};