class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int mul = 1;
            for(int j=i; j<n; j++)
            {
                mul = mul*v[j];
                maxi = max(maxi,mul);
            }
        }

        return maxi;
    }
};