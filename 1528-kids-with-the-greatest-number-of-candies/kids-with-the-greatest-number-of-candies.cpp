class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int e) {
        int n = v.size();
        vector<bool> ans(n, true);

        int mx = -1;
        for (int x : v)
            mx = max(mx, x);

        for (int i = 0; i < n; i++) {
            if (v[i] + e < mx)
                ans[i] = false;
        }

        return ans;
    }
};