class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int mx = 0;
        string ans = "";
        int st = 0;
        int e = 0;
        
        for(int k=0; k<n; k++)
        {
            int i = k;
            int j = k;

            while(i>=0 && j<n)
            {
                if(s[i]==s[j])
                {
                    if(j-i+1>mx)
                    {
                        mx = j-i+1;
                        st = i;
                        e = j;
                    }
                    i--;
                    j++;
                }
                else
                {
                    break;
                }
            }

            i = k;
            j = k+1;

            while(i>=0 && j<n)
            {
                if(s[i]==s[j])
                {
                    if(j-i+1>mx)
                    {
                        mx = j-i+1;
                        st = i;
                        e = j;
                    }
                    i--;
                    j++;
                }
                else
                {
                    break;
                }
            }
        }

        return s.substr(st,e-st+1);
    }
};