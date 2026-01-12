class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char,int> mp;
        int last = -1;
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            if(mp.find(ch)!=mp.end())
            {
                int id = mp[ch];
                last = max(last,id);
            }
            ans=max(ans,i-last);
            mp[ch] = i;
        }

        return ans;
    }
};