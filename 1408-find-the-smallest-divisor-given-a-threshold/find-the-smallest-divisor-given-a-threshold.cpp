class Solution {
public:
    bool check(int d, vector<int> &v, int t)
    {
        int cnt = 0;
        for(auto it: v)
        {
            cnt+= (it+d-1)/d;
        }

        return (cnt<=t);
    }
    int smallestDivisor(vector<int>& v, int t) {
        int n = v.size();

        int s = 1;
        int e = *max_element(v.begin(), v.end());

        int ans = 1;

        while(s<=e)
        {
            int mid = (s+e)/2;

            if(check(mid,v,t))
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