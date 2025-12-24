class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();

        for (int index = 0; index < size; index++) {
            if (nums[index] == target) {
                return true;
            }
        }

        return false;
    }
};