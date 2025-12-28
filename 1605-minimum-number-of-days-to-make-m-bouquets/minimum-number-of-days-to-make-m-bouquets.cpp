class Solution {
public:
    bool check(int d,vector<int>& v, int m, int k)
    {
        int n = v.size();

        int cnt = 0;
        int b = 0;

        for(int i=0; i<n; i++)
        {
            if(v[i]<=d)
            {
                // bloomed
                cnt++;
                if(i==n-1)
                {
                    b+= cnt/k;
                }
            }
            else
            {
                b+= cnt/k;
                cnt=0;
            }
        }

        return b>=m;
    }

    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();

        if((n/k)<m)
        {
            return -1;
        }

        int s = INT_MAX;
        int e = 0;
        for(auto it: v)
        {
            s = min(s,it);
            e = max(e,it);
        }
        int ans = 0;

        while(s<=e)
        {
            int mid = (s+e)/2;

            if(check(mid,v,m,k))
            {
                ans=mid;
                e = mid-1;
            }
            else
            {
                s=mid+1;
            }
        }

        return ans;
    }
};