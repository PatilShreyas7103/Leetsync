class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < arr.size(); i++)
            nums.push_back({arr[i], i});

        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l].first + nums[r].first;
            if (sum == target)
                return {nums[l].second, nums[r].second};
            else if (sum < target)
                l++;
            else
                r--;
        }

        return {-1, -1};
    }
};