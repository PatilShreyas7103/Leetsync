class Solution {
public:
    bool uniqueOccurrences(vector<int>& v) {
        map<int,int> mp;
        for(auto it: v)
        {
            mp[it]++;
        }
        int sz = mp.size();
        set<int> st;
        for(auto it: mp)
        {
            st.insert(it.second);
        }

        return (st.size()==sz);
    }
};