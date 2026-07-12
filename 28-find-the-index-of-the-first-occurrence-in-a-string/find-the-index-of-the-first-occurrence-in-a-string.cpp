class Solution {
public:
    int strStr(string h, string s) {
        int m = h.length();
        int n = s.length();
        int ans = -1;

        for(int i=0; i<m; i++)
        {
            if(h.substr(i,n)==s)
            {
                ans =  i;
                break;
            }
        }

        return ans;
    }
};