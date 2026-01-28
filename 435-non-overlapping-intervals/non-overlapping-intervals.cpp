class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();

        vector<pair<int,int>> p;
        for(auto it: v)
        {
            p.push_back({it[1],it[0]}); // {end,start}
        }

        sort(p.begin(),p.end());

        int last = INT_MIN;
        int ans = 0;
        for(auto it: p)
        {
            int s1 = it.second;
            int e1 = it.first;

            if(s1>=last)
            {
                last = e1;
            }
            else
            {
                ans++;
            }
        }

        return ans;
    }
};