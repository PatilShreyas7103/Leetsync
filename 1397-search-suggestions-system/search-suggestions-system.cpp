class Solution {
public:
    bool check(string p, string q)
    {
        int n = p.length();
        int m = q.length();
        int i = 0;
        int j = 0;
        if(m<n)
        {
            return false;
        }

        while(i<n)
        {
            if(p[i]!=q[j])
            {
                return false;
            }
            i++;
            j++;
        }

        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& v, string s) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<string>> ans;
        int len = s.length();

        int l = 0;
        int r = n-1;
        string str = "";
        int cnt = 0;
        int id = 0;
        while(l<=r && id<len)
        {
            vector<string> res;
            str+= s[id];
            id++;
            bool valid = false;
            while(!valid && l<n)
            {
                valid = check(str,v[l]);
                if(!valid)
                {
                    l++;
                }
            }

            valid = false;
            while(!valid && r>=0)
            {
                valid = check(str,v[r]);
                if(!valid)
                {
                    r--;
                }
            }

            if(l<=r)
            {
                cnt++;
                int k = 3;
                int l1 = l;
                while(k-- && l1<=r)
                {
                    res.push_back(v[l1]);
                    l1++;
                }
                ans.push_back(res);
            }
        }

        while(cnt<len)
        {
            cnt++;
            ans.push_back({});
        }
        return ans;

    }
};