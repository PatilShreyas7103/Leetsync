class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();

        unordered_map<int,int> mp;
        for(auto it: v)
        {
            mp[it]++;
            if(mp[it]>n/2){
                return it;
            }
        }

        return -1;
    }
};