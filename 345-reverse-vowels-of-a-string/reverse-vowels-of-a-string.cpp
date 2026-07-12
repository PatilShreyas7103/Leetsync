class Solution {
public:
    bool isVowel(char ch)
    {
        return (ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U' );
    }
    string reverseVowels(string s) {
        int n = s.length();

        int i = 0;
        int j = n-1;

        while(i<j)
        {
            while(!isVowel(s[i]))
            {
                i++;
                if(i>j)
                {
                    break;
                }
            }
            while(!isVowel(s[j]))
            {
                j--;
                if(i>j)
                {
                    break;
                }
            }
            if(isVowel(s[i]) && isVowel(s[j]))
                {
                    swap(s[i],s[j]);
                }
            i++;
            j--;
        }

        return s;
    }
};