class Solution {
public:
    int myPow(long long x, long long n) {
        int ans = 1;
        int mod = 1e9+7;
        int p = n;
        if(n<0)
        {
            n = -n;
        }
        if(n==0)
        {
            return 1;
        }
        while(n>0)
        {
            if(n&1)
            {
                ans = (ans*x)%mod;
                n--;
            }
            else
            {
                n = n/2;
                x = (x*x)%mod;
            }
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        int mod = 1e9+7;
        long long ans = 0;
        if(n&1)
        {
            ans = myPow (20,n/2)*(long long)5;
        }
        else
        {
            ans = myPow (20,n/2);
        }

        return ans%mod;
    }
};