class Solution {
public:
    bool wordPattern(string p, string s) {
        int i = 0;
        int n = p.size();
        map<char,string> mp;
        map<string,char> mpp;
        string curr = "";
        for(auto it: s)
        {
            if(it==' ')
            {
                if(mp.find(p[i])==mp.end())
                {
                    mp[p[i]] = curr;
                }
                else
                {
                    if(mp[p[i]]!=curr)
                    {
                        return false;
                    }
                }
                curr = "";
                i++;
            }
            else
            {
                curr+= it;
            }
        }
        if(mp.find(p[i])==mp.end())
                {
                    mp[p[i]] = curr;
                }
                else
                {
                    if(mp[p[i]]!=curr)
                    {
                        return false;
                    }
                }
        curr = "";
        i=0;
        for(auto it: s)
        {
            if(it==' ')
            {
                if(mpp.find(curr)==mpp.end())
                {
                    mpp[curr] = p[i];
                }
                else
                {
                    if(mpp[curr]!=p[i])
                    {
                        return false;
                    }
                }
                curr = "";
                i++;
            }
            else
            {
                curr+= it;
            }
        }
        if(mpp.find(curr)==mpp.end())
                {
                    mpp[curr] = p[i];
                }
                else
                {
                    if(mpp[curr]!=p[i])
                    {
                        return false;
                    }
                }

        return i==n-1;
    }
};