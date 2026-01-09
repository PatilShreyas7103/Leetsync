class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int l = -1;
        int r = n;

        for(auto it: v)
        {
            if(it==0)
            {
                l++;
            }
            else if(it==2)
            {
                r--;
            }
        }

        for(int i=0; i<=l; i++)
        {
            v[i] = 0;
        }
        for(int i=n-1; i>=r; i--)
        {
            v[i] = 2;
        }
        for(int i=l+1; i<r; i++)
        {
            v[i] = 1;
        }
    }
};