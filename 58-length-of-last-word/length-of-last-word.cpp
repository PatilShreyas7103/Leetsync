class Solution {
public:
    int lengthOfLastWord(string s) {
        int id = s.length()-1;
        int len = 0;

        while(id>=0 && s[id]==' ')
        {
            id--;
        }
        while(id>=0 && s[id]!=' ')
        {
            len++;
            id--;
        }

        return len;
    }
};