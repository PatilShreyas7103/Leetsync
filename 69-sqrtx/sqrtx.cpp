class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
        {
            return x;
        }
        long long ans = 1;
        for(int i=1; i<=x; i++)
        {
            long long sq = (long long)i*i;
            if(sq==x)
            {
                return i;
            }
            else if(sq<x)
            {
                ans = i;
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};