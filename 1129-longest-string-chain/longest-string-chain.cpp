class Solution {
public:
    bool valid(string p, string q)
    {
        // p must be longger
        int m = p.length();
        int n = q.length();

        if(n+1!=m)
        {
            return false;
        }
        int j = 0;
        int cnt = 0;
        for(int i=0; i<m; i++)
        {
            if(p[i]==q[j])
            {
                j++;
            }
            else
            {
                cnt++;
            }
        }
        if(cnt==1)
        {
            return true;
        }
        return false;
    }
    int solve(int i, int prev, vector<string> &v, int n)
    {
        if(i==n)
        {
            return 0;
        }

        int dont = solve(i+1,prev,v,n);
        int take = 0;

        if(prev==-1)
        {
            // first string
            take = 1+solve(i+1,i,v,n);
        }
        else
        {
            if(valid(v[i],v[prev]))
            {
                take = 1+solve(i+1,i,v,n);
            }
        }

        return max(take,dont);
    }

    int longestStrChain(vector<string>& v) {
        int n = v.size();

        vector<int> dp(n,1);
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int k1 = v[i].size();
                int k2 = v[j].size();

                if(k2<k1)
                {
                    swap(v[i],v[j]);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(valid(v[i], v[j]))
                {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }

        // return solve(0,-1,v,n);
        return ans;
    }
};