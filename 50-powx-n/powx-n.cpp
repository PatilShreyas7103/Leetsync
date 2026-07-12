class Solution {
public:
    double myPow(double x, long long n) {
        double ans = 1;
        int p = n;
        if(n<0)
        {
            n = -n;
        }
        if(n==0)
        {
            return 1.0;
        }
        while(n>0)
        {
            if(n&1)
            {
                ans = ans*x;
                n--;
            }
            else
            {
                n = n/2;
                x = x*x;
            }
        }
        if(p>0)
        {
            return ans;
        }
        else
        {
            return (1.0/ans);
        }
    }
};