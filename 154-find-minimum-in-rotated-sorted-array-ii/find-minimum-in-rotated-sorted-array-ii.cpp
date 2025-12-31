class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0 , e = n -1 , minEle = INT_MAX;

        while( s <= e){
            int mid = s + (e - s)/2;
            if(nums[s] == nums[mid] && nums[mid] == nums[e]){
                minEle = min( minEle , nums[s]);
                s++ , e-- ;
                continue;
            }
            if(nums[s] <= nums[mid] ){
                minEle = min( minEle , nums[s]);
                s = mid +1;
            }else{
                minEle = min( minEle , nums[mid]);
                e = mid - 1;
            }
        }   
            return minEle ;
    }
};