class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto it: nums)
        {
            v.push_back(to_string(it));
        }
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                string p = v[i];
                string q = v[j];
                if(p+q<q+p)
                {
                    swap(v[i],v[j]);
                }
            }
        }
        if(v[0]=="0")
        {
            return "0";
        }

        string ans = "";
        for(auto &s: v)
        {
            ans+=s;
        }

        return ans;
    }
};