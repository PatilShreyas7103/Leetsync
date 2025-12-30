class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> v;
        int i = 0;
        int j = 0;

        int m = a.size();
        int n = b.size();

        while(i<m && j<n)
        {
            if(a[i]<b[j])
            {
                v.push_back(a[i]);
                i++;
            }
            else
            {
                v.push_back(b[j]);
                j++;
            }
        }

        while(i<m)
        {
            v.push_back(a[i]);
            i++;
        }
        while(j<n)
        {
            v.push_back(b[j]);
            j++;
        }

        int sz = v.size();
        if(sz&1)
        {
            return v[sz/2];
        }
        else
        {
            return (double)(v[sz/2]+v[sz/2-1])/2.0;
        }
    }
};