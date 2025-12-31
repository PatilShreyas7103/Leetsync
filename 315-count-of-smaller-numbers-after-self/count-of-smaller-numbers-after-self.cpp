class Solution {
public:
    vector<int> countSmaller(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n,0);
        vector<int> sorted;

        for(int i=n-1; i>=0; i--)
        {
            auto pos = lower_bound(sorted.begin(), sorted.end(), v[i]);
            int cnt = pos-sorted.begin();
            sorted.insert(pos, v[i]);
            ans[i] = cnt;
        }

        return ans;
    }
};