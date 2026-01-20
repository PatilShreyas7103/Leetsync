class Solution {
public:
    void solve(int i,int n, int dots,string s, string curr, vector<string> &ans)
    {
        if(dots==4 && i==n)
        {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(dots>4)
        {
            return;
        }
        int id = min(i+3,n-1);
        for(int j=i; j<=id;j++)
        {
            string temp = s.substr(i,j-i+1);
            int d = stoi(temp);

            if(d<256 && (i==j || s[i]!='0'))
            {
                solve(j+1,n,dots+1,s,curr+temp+'.',ans);
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string> ans;
        if(n<4 || n>12)
        {
            return ans;
        }

        solve(0,n,0,s,"",ans);

        return ans;
        
    }
};