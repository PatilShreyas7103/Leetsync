class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size();
        int n = v[0].size();

        int i= 0;
        int j = m-1;
        bool f = false;
        int row = -1;

        while(i<=j)
        {
            int mid = (i+j)/2;

            int s = v[mid][0];
            int e = v[mid][n-1];

            if(t>=s && t<=e)
            {
                // found row
                f = true;
                row = mid;
                break;
            }
            else if(t<s)
            {
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }

        if(!f){
            return false;
        }
        int s =0;
        int e = n-1;

        while(s<=e)
        {
            int mid = (s+e)/2;
            int element = v[row][mid];

            if(element==t)
            {
                return true;
            }
            else if(element<t)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }

        return false;
    }
};