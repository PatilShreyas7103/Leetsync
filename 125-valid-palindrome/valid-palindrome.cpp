class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto it: s)
        {
            if(it>='a' && it<='z')
            {
                // lowercase
                temp+=it;
            }
            else if(it>='A' && it<='Z')
            {
                // uppercase
                temp+= it+32;
            }
            else if(it>='0' && it<='9')
            {
                // skip
                temp+=it;
            }
        }
        int n = temp.length();
        int i = 0;
        int j = n-1;

        while(i<=j)
        {
            if(temp[i]!=temp[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};