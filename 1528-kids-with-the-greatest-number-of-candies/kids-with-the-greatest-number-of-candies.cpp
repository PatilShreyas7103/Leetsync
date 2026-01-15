class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int e) {
        int n = v.size();
        vector<bool> ans(n,true);
        for(int i=0; i<n; i++)
        {
            int val = v[i]+e;
            bool f = true;
            for(int j=0; j<n; j++)
            {
                if(v[j]>val)
                {
                    f = false;
                    break;
                }
            }
            ans[i] = f;
        }

        return ans;
    }
};