class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int n = v.size();

        vector<int> p(n,0);
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            p[i] += sum;
            sum+=v[i];
        }
        sum = 0;
        int ans = -1;
        for(int i=n-1; i>=0; i--)
        {
            p[i] += sum;
            if(p[i]==0)
            {
                ans=i;
            }
            sum-=v[i];
        }

        return ans;
    }
};