class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;

        while(i<=j)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                // lowercase
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                // convert
                s[i]+=32;
            }   
            else if(s[i]>='0' && s[i]<='9')
            {
                // number
            }
            else
            {
                i++;
                continue;
            }

            if(s[j]>='a' && s[j]<='z')
            {
                // lowercase
            }
            else if(s[j]>='A' && s[j]<='Z')
            {
                // convert
                s[j]+=32;
            }   
            else if(s[j]>='0' && s[j]<='9')
            {
                // number
            }
            else
            {
                j--;
                continue;
            }
            if(i>j)
            {
                break;
            }
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};