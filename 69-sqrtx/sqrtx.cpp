class Solution {
public:
    int mySqrt(int x) {
        long long s = 0;
        long long e = x/2;
        long long ans = 0;
        if(x==0 || x==1)
        {
            return x;
        }
        while(s<=e)
        {
            long long mid = (s+e)/2;
            long long sq = (long long)mid*mid;

            if(sq==x)
            {
                return mid;
            }
            else if(sq<x)
            {
                ans=mid;
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }

        return ans;
    }
};