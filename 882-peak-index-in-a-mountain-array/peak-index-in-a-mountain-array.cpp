class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size();
        int s = 1;
        int e = n-2;

        while(s<=e)
        {
            int mid = (s+e)/2;
            int prev = mid-1;
            int next = mid+1;

            if(v[mid]>v[prev] && v[mid]>v[next])
            {
                return mid;
            }
            else if(v[prev]>v[mid])
            {
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }   

        return -1;
    }
};