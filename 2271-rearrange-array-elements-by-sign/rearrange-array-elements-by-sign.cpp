class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n);
        int p = 0;
        int ne = 1;
        for(int i=0; i<n; i++)
        {
            if(v[i]>0)
            {
                ans[p] = v[i];
                p+=2;
            }
            else
            {
                ans[ne] = v[i];
                ne+=2;
            }
        }

        return ans;
    }
};