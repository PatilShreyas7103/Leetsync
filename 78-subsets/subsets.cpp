class Solution {
public:
    void solve(int n,vector<int> &v, vector<int> ans, vector<vector<int>> &res)
    {
        if(n<0)
        {
            res.push_back(ans);
            return;
        }

        solve(n-1,v,ans,res);
        ans.push_back(v[n]);
        solve(n-1,v,ans,res);
    }

    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size();

        vector<vector<int>> res;
        vector<int> ans;
        solve(n-1,v,ans,res);

        return res;
    }
};