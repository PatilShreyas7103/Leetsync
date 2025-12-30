class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();

        if(m>n)
        {
            return findMedianSortedArrays(b,a);
        }
        int s = 0;
        int e = m;
        int middle = (m+n+1)/2;
        int tot = m+n;

        while(s<=e)
        {
            int cut1 = (s+e)/2;
            int cut2 = middle-cut1;

            int l1 = cut1==0 ? INT_MIN : a[cut1-1];
            int l2 = cut2==0 ? INT_MIN : b[cut2-1];

            int r1 = cut1==m ? INT_MAX : a[cut1];
            int r2 = cut2==n ? INT_MAX : b[cut2];

            if(l1<=r2 && l2<=r1)
            {
                if(tot&1){
                    return double(max(l1,l2));
                }
                else
                {
                    return double(max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1>r2)
            {
                e = cut1-1;
            }
            else
            {
                s = cut1+1;
            }
            
        }

        return 0.0;
    }
};