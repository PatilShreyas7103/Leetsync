
class Solution {
public:
    int solve(string s) {
        int n = s.length();
        int mx = 0;
        int ans = 0;
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
                    ans++;
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
                    ans++;
                    i--;
                    j++;
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }

    int countSubstrings(string s) {
        return solve(s);
    }
};