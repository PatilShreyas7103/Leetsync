class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size();
        int ans = -1;
        if(n==1)
        {
            return 0;
        }

        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                if(v[i]>v[i+1])
                {
                    return 0;
                }
            }
            else if(i==n-1)
            {
                if(v[i]>v[i-1])
                {
                    return n-1;
                }
            }
            else
            {
                if(v[i]>v[i+1] && v[i]>v[i-1])
                {
                    return i;
                }
            }

        }

        return ans;
    }
};