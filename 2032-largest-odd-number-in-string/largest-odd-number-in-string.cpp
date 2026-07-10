class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.length();
        int r = -1;

        for(int i=n-1; i>=0; i--)
        {
            if((s[i]-'0')&1)
            {
                r = i;
                break;
            }
        }
        if(r==-1)
        {
            return "";
        }

        return s.substr(0,r+1);
    }
};