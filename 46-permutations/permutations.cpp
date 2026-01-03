class Solution {
public:
    void solve(int i, int n, vector<int> &ans,vector<vector<int>> &res,
    unordered_map<int,int> &vis, vector<int> &v)
    {
        if(i==n)
        {
            res.push_back(ans);
            return;
        }

        for(int j=0; j<n;j++)
        {
            int val = v[j];
            if(vis[val])
            {
                continue;
            }
            ans.push_back(val);
            vis[val] = 1;

            solve(i+1,n,ans,res,vis,v);
            ans.pop_back();
            vis[val] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> res;
        vector<int> ans;
        int n = v.size();
        unordered_map<int,int> vis;

        solve(0,n,ans,res,vis,v);

        return res;
    }
};