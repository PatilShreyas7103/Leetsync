class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }
        int n = s.length();

        for(int i=0; i<n; i++)
        {
            if(mp[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};