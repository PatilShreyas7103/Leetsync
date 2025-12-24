class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n = v.size();
        int s = 0;
        int e = n-1;

        while(s<=e)
        {
            int mid = (s+e)/2;
            if(s==e)
            {
                return v[s];
            }

            if(mid%2==0)
            {
                if(v[mid]==v[mid+1])
                {
                    s = mid+2;
                }
                else
                {
                    e = mid;
                }
            }
            else
            {
                if(v[mid]==v[mid-1])
                {
                    s = mid+1;
                }
                else
                {
                    e = mid-1;
                }
            }
        }

        return v[s];
    }
};