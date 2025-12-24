class Solution {
public:
    int search(vector<int>& v, int t) {
        int n = v.size();

        int s = 0;
        int e = n-1;

        while(s<=e)
        {
            int mid = (s+e)/2;
            if(v[mid]==t)
            {
                return mid;
            }
            else if(t>v[mid])
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }

        return -1;
    }
};