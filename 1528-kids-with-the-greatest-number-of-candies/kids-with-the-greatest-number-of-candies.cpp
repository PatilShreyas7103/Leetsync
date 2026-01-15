class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int e) {
        int n = v.size();
        vector<bool> ans(n,true);
        int mx = -1;
        int sec = -1;

        for(int i=0; i<n; i++)
        {
            if(v[i]>mx)
            {
                sec = mx;
                mx = v[i];
            }
            else if(v[i]<mx && v[i]>sec)
            {
                sec = v[i];
            }
        }

        for(int i=0; i<n; i++)
        {
            if(v[i]==mx)
            {
                ans[i] = 1;
            }
            else
            {
                int val = v[i]+e;
                if(mx>val)
                {
                    ans[i] = 0;
                }
            }
        }

        return ans;
    }
};