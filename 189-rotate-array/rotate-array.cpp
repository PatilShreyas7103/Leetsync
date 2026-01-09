class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        if(k==0)
        {
            return;
        }
        k%=n;
        vector<int> ans;
        for(int i=n-k; i<n;i++)
        {
            ans.push_back(v[i]);
        }
        for(int i=0; i<n-k;i++)
        {
            ans.push_back(v[i]);
        }
        v = ans;
    }
};