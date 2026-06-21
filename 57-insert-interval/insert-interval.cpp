class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v,
                               vector<int>& k) {
        int n = v.size(), i = 0;
        vector<vector<int>> res;

        while (i < n && v[i][1] < k[0]) {
            res.push_back(v[i]);
            i++;
        }

        while (i < n && k[1] >= v[i][0]) {
            k[0] = min(k[0], v[i][0]);
            k[1] = max(k[1], v[i][1]);
            i++;
        }
        res.push_back(k);

        while (i < n) {
            res.push_back(v[i]);
            i++;
        }
        return res;
    }
};