class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int> f(26,0);

        for(auto it:m)
        {
            f[it-'a']++;
        }
         for(auto it:r)
        {
            f[it-'a']--;
            if(f[it-'a']<0)
            {
                return false;
            }
        }

        return true;
    }
};