class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int x = 0;
        for(auto it: v)
        {
            x^=it;
        }

        return x;
    }
};