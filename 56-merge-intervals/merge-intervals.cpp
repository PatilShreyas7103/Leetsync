class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<pair<int,int>> p;
        vector<vector<int>> ans;

        for(auto it: v)
        {
            int a = it[0];
            int b = it[1];

            p.push_back({a,b});
        }

        sort(p.begin(), p.end());

        int s = p[0].first;
        int e = p[0].second;
        int sz = p.size();

        for(int i=1; i<sz; i++)
        {
            int s1 = p[i].first;
            int e1 = p[i].second;

            if(s1<=e)
            {
                e = max(e,e1);
            }
            else
            {
                ans.push_back({s,e});
                s = s1;
                e = e1;
            }
        }
        ans.push_back({s,e});

        return ans;
    }
};