class Solution {
public:
    string convertToTitle(int c) {
        string ans =  "";
        while(c>0)
        {
            int d = (c-1)%26;
            char ch = d+'A';
            ans+=ch;
            c = (c-1)/26;
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};