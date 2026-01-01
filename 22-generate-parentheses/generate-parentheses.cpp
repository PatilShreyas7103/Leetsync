class Solution {
public:
    void solve(int n1, int n2, string s, vector<string> &ans)
    {
        if(n2<n1)
        {
            return;
        }
        if(n1<0 || n2<0)
        {
            return;
        }
        if(n1==0 && n2==0)
        {
            ans.push_back(s);
            return;
        }
        

        solve(n1-1,n2,s+'(',ans);
        solve(n1,n2-1,s+')',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        solve(n,n,s,ans);

        return ans;
    }
};