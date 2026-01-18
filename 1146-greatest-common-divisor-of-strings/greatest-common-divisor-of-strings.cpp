class Solution {
public:
    bool valid(string ans, string s, string t, int m, int n)
    {
        int sz = ans.length();
        if(sz>m || sz>n)
        {
            return false;
        }
        int r1 = (m+sz-1)/sz;
        int r2 = (n+sz-1)/sz;

        string k = "";
        for(int i=1; i<=r1; i++)
        {
            k+=ans;
        }
        if(k!=s)
        {
            return false;
        }
        k = "";
        for(int i=1; i<=r2; i++)
        {
            k+=ans;
        }
        if(k!=t)
        {
            return false;
        }

        return true;
    }
    string gcdOfStrings(string s, string t) {
        int m = s.length();
        int n = t.length();

        string ans = "";
        string res = "";

        for(int i=0; i<n; i++)
        {
            ans+=t[i];
            if(valid(ans,s,t,m,n))
            {
                res = ans;
            }
        }

        return res;

    }
};