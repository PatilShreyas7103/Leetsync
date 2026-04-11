class Solution {
public:
    void solve(int i, int t, vector<int> &v,
    vector<vector<int>> &ans, vector<int> curr)
    {
        if(i==0)
        {
            if(t%v[0]==0)
            {
                int f = t/v[0];
                while(f--)
                {
                    curr.push_back(v[0]);
                }
                ans.push_back(curr);
                
            }
            return;
        }

        solve(i-1,t,v,ans,curr);
        if(v[i]<=t)
        {
            curr.push_back(v[i]);
            solve(i,t-v[i],v,ans,curr);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& v, int t) {
        vector<vector<int>> ans;
        vector<int> curr;

        int n = v.size();
        solve(n-1,t,v,ans,curr);

        return ans;
    }
};