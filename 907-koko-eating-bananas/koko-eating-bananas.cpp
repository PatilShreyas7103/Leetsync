class Solution {
public:
    bool check(int k, vector<int> &v,int h)
    {
        long long cnt = 0;
        for(long long it: v)
        {
            cnt+= (long long)(it+k-1)/k;
        }

        if(cnt<=h)
        {
            return 1;
        }
        return 0;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        long long mx = 0;
        for(long long it: v)
        {
            mx = max(mx,it);
        }
        long long n = v.size();

        long long s = 1;
        long long e = mx;
        long long ans = 0;

        while(s<=e)
        {
            long long mid  = (s+e)/2;

            if(check(mid,v,h))
            {
                ans = mid;
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