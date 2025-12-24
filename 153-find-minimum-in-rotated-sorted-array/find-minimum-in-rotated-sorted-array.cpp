class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int s = 0;
        int e = n-1;
        int ans = INT_MAX;

        while(s<=e)
        {
            int mid = (s+e)/2;
            if (nums[s] <= nums[e]) 
            {
                ans = min(ans, nums[s]);
                break;
            }
            if(nums[s]<=nums[mid])
            {
                // Left part is sorted
                ans = min(ans,nums[s]);
                s = mid+1;
            }
            else
            {
                // Right part is sorted
                ans = min(ans,nums[mid]);
                e = mid-1;
            }
        }
        return ans;
    }
};