
class Solution {
public:
    bool isValid(string s)
    {
        int i  = 0;
        int j = s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    int solve(string s) {
        int n = s.length();
        int mx = 0;
        int ans = 0;

        for(int i=0;i<n; i++)
        {
            string str = "";
            for(int j=i; j<n; j++)
            {
                str+= s[j];
                if(isValid(str))
                {   
                    ans++;
                }
                
            }
        }

        return ans;
    }

    int countSubstrings(string s) {
        return solve(s);
    }
};