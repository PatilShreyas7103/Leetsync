class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        int c1 = 0, c2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;

        for (int x : v) {
            if (x == e1)
                c1++;
            else if (x == e2)
                c2++;
            else if (c1 == 0) {
                e1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                e2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = c2 = 0;
        for (int x : v) {
            if (x == e1) c1++;
            else if (x == e2) c2++;
        }

        vector<int> ans;
        if (c1 > n / 3) ans.push_back(e1);
        if (c2 > n / 3) ans.push_back(e2);

        return ans;
    }
};