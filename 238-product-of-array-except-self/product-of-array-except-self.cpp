class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        vector<int> res;
        int n = v.size();
        int cnt = 0;
        int ans = 1;

        for(int i=0; i<n; i++)
        {
            if(v[i]==0)
            {
                cnt++;
            }
            else
            {
                ans*=v[i];
            }
        }

        if(cnt==0)
        {
            // normal
            for(auto it:v)
            {
                res.push_back(ans/it);
            }
        }
        else if(cnt==1)
        {
            // contains single zero
            for(auto it:v)
            {
                if(it==0)
                {
                    res.push_back(ans);
                }
                else
                {
                    res.push_back(0);
                }
            }
        }
        else
        {
            for(auto it:v)
            {
                res.push_back(0);
            }
        }

        return res;
    }
};