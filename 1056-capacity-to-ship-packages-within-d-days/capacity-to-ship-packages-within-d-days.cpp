class Solution {
public:
    bool check(int c, vector<int> &v, int d)
    {
        int sum = 0;
        int n = v.size();
        int cnt = 0;

        for(int i=0; i<n; i++)
        {
            if(v[i]>c)
            {
                return false;
            }
            if(sum+v[i]<=c)
            {
                sum+= v[i];
            }
            else
            {
                cnt++;
                sum = v[i];
            }
        }

        return (cnt+1)<=d;
    }


    int shipWithinDays(vector<int>& v, int d) {
        
        int s = 1;
        int e = accumulate(v.begin(), v.end(),0);
        int ans = e;

        while(s<=e)
        {
            int mid = (s+e)/2;

            if(check(mid,v,d))
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