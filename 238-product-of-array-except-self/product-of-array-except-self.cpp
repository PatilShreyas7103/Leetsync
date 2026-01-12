class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> res(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix *= v[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= v[i];
        }

        return res;
    }
};