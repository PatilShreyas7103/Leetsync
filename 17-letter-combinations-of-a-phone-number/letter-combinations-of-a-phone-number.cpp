class Solution {
public:
    void solve(int i, string s, map<int,string> &mp, string curr, vector<string> &ans)
    {
        if(i==s.size())
        {
            ans.push_back(curr);
            return;
        }

        for(char ch: mp[s[i]-'0'])
        {
            string temp = curr+ch;
            solve(i+1,s,mp,temp,ans);
        }
    }
    vector<string> letterCombinations(string s) {
        vector<string> ans;
        string curr = "";

        map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        solve(0,s,mp,curr,ans);

        return ans;
    }
};