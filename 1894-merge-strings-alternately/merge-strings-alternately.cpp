class Solution {
public:
    string mergeAlternately(string a, string b) {
        string ans = "";
        int m = a.size();
        int n = b.size();
        int i = 0;
        int j = 0;

        while(i<m && j<n)
        {
            ans+= a[i];
            ans+= b[j];
            i++;
            j++;
        }

        while(i<m)
        {
            ans+= a[i];
            i++;
        }
        while(j<n)
        {
            ans+= b[j];
            j++;
        }

        return ans;
    }
};