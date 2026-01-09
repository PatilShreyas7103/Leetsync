class Solution {
public:
    int missingNumber(vector<int>& v) {
        int sum = 0;
        int n = v.size();
        for(auto it: v)
        {
            sum+=it;
        }

        return (n*(n+1))/2 - sum;
    }
};