class Solution {
public:
    bool check(char ch)
    {
        return (ch>='0' && ch<='9');
    }
    int myAtoi(string s) {
        int n = s.length();

        int id = 0;
        int sign = 1;
        while(id<n && s[id]==' ')
        {
            id++;
        }
        if(id==n)
        {
            return 0;
        }
        if(s[id]=='-')
        {
            sign = -1;
            id++;
        }
        else if(s[id]=='+')
        {
            id++;
        }

        long long num = 0;
        while(id<n && check(s[id]))
        {
            num = num*10 + s[id]-'0';

            if(sign*num>=INT_MAX)
            {
                return INT_MAX;
            }
            if(sign*num<=INT_MIN)
            {
                return INT_MIN;
            }
            id++;
        }

        return (int)sign*num;
    }
};