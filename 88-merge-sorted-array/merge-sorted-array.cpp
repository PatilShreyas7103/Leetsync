class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m-1;
        int j = n-1;
        int id = m+n-1;

        while(i>=0 && j>=0)
        {
            if(a[i]<b[j])
            {
                a[id] = b[j];
                j--;
                id--;
            }
            else
            {
                a[id] = a[i];
                i--;
                id--;
            }
        }
        while(j>=0)
        {
            a[id] = b[j];
            j--;
            id--;
        }
        while(i>=0)
        {
            a[id] = a[i];
            i--;
            id--;
        }
    }
};