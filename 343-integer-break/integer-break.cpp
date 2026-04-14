class Solution {
public:

    int integerBreak(int n) {
        int ans = 0;
        for(int k=2; k<=n; k++)
        {
            int num1 = n/k; // floor
            int num2 = (n+k-1)/k; // ceil

            int f = n%k;
            int mul = pow(num2,f) * pow(num1,k-f);
            ans=max(ans,mul);
        }

        return ans;
    }
};