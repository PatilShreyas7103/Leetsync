class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int mn = INT_MAX;
        int ans = 0;

        for(auto it: p)
        {
            ans=max(ans,it-mn);
            mn = min(mn, it);
        }


        return ans;
    }
};