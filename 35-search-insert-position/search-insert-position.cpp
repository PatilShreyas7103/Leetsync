class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        int n = v.size();
        
        int ans = 0 ;
        int s = 0;
        int e = n-1;

        while(s<=e)
        {
            int mid = (s+e)/2;

            if(v[mid]==t)
            {
                return mid;
            }
            else if(v[mid]>t)
            {
                e = mid-1;
            }
            else
            {
                ans=mid+1;
                s = mid+1;
            }
        }
        
        return ans;
    }
};