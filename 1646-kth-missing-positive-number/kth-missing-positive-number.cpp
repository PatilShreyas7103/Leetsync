class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int n = v.size();

        int s = 0;
        int e = n-1;

        while(s<=e){
            int mid = (s+e)/2;

            int miss = v[mid]-mid-1;

            if(miss<k)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }

        return e+k+1;
    }
};