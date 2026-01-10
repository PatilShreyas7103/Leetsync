class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto it: v)
        {
            mp[it]++;
        }

        for(auto it: mp)
        {
            if(it.second>n/3)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};