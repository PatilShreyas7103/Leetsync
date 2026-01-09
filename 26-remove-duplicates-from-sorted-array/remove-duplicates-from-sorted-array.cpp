class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        map<int,int> mp;
        for(auto it: v)
        {
            mp[it]++;
        }
        int id = 0;
        for(auto it: mp)
        {
            int e = it.first;
            v[id++] =  e;
        }

        return mp.size();
    }
};