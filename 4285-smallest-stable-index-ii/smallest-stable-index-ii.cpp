class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> _min(n, 0);
        for(int i=n-1; i>=0;i--)
        {
            _min[i] = (i==n-1) ? nums[i] : min(nums[i], _min[i+1]);
        }
        int _max = INT_MIN;
        for(int i=0; i<n;i++) {
            _max = max(nums[i], _max);
            if(_max - _min[i] <= k) return i;

        }
        return -1;
    }
};