class Solution {
public:
    void rev(vector<int> &v, int i, int j)
    {
        while(i<j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k%=n;
        if(k==0 || n==1)
        {
            return;
        }
        rev(v,0,n-k-1);
        rev(v,n-k,n-1);
        rev(v,0,n-1);

    }
};