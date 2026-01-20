class Solution {
public:
    string addStrings(string s, string t) {
        int m = s.length();
        int n = t.length();

        int i = m-1;
        int j = n-1;
        int car = 0;
        string ans = "";

        while(i>=0 || j>=0 || car)
        {
            int sum = car;
            if(i>=0)
            {
                sum+= s[i]-'0';
                i--;
            }
            if(j>=0)
            {
                sum+=t[j]-'0';
                j--;
            }
            ans+=sum%10+'0';
            car = sum/10;
        }


        reverse(ans.begin(), ans.end());

        return ans;

    }
};