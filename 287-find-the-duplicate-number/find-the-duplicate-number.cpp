class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int sz = v.size();
        int n = sz-1;

        unordered_map<int,int> mp;
        for(auto it: v)
        {
            mp[it]++;
            if(mp[it]==2)
            {
                return it;
            }
        }

        return -1;
    }
};