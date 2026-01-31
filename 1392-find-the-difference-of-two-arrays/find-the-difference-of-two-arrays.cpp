class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {

        map<int,int> mp;
        for(auto it: a)
        {
            mp[it]=1;
        }

        for(auto it: b)
        {
            if(mp.count(it)>0)
            {
                mp.erase(it);
            }
        }
        vector<int> ans1;
        for(auto it: mp)
        {
            ans1.push_back(it.first);
        }
        mp.clear();

        for(auto it: b)
        {
            mp[it]=1;
        }

        for(auto it: a)
        {
            if(mp.count(it)>0)
            {
                mp.erase(it);
            }
        }
        vector<int> ans2;
        for(auto it: mp)
        {
            ans2.push_back(it.first);
        }

        vector<vector<int>> res;
        res.push_back(ans1);
        res.push_back(ans2);

        return res;

    }
};