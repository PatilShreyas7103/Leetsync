class Solution {
public:
    bool check(int lim, vector<int> &v, int k)
    {
        int sum = 0;
        int cnt = 1;

        for(auto it: v)
        {
            if(sum+it<=lim)
            {
                sum+=it;
            }
            else
            {
                cnt++;
                sum = it;
            }
        }

        return cnt<=k;
    }
    int splitArray(vector<int>& v, int k) {
        int n = v.size();
        int s = *max_element(v.begin(), v.end());
        int e = accumulate(v.begin(), v.end(),0);

        int ans = 0;

        while(s<=e)
        {
            int mid = (s+e)/2;

            if(check(mid,v,k))
            {
                ans=mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
        }

        return ans;
    }
};