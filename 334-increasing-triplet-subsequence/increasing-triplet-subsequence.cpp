class Solution {
public:
    bool increasingTriplet(vector<int>& v) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int x : v) {
            if (x <= first)
                first = x;
            else if (x <= second)
                second = x;
            else
                return true;
        }

        return false;
    }
};