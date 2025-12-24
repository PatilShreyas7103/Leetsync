class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1)
        {
            if(nums[0]==target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int s = 0;
        int e = n-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            // Left part is sorted
            if(nums[mid]==target)
            {
                return true;
            }
            if (nums[s] == nums[mid] && nums[mid] == nums[e]) 
            {
                s = s + 1;
                e = e - 1;
                continue;
            }

            if(nums[s]<=nums[mid])
            {
                if(nums[s]<=target && target<=nums[mid])
                {
                    e = mid-1;
                }
                else
                {
                    s = mid+1;
                }
            }
            else
            {
                // Right part is sorted
                if(nums[mid]<=target && target<=nums[e])
                {
                    s = mid+1;
                }
                else
                {
                    e = mid-1;
                }
            }
        }

        return false;
    }
};