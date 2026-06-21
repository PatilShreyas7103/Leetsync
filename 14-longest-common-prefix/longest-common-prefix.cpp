class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n = str.size();
        sort(str.begin(), str.end());

        string one = str[0];
        string last = str[n-1];
        int mini = min(one.length(), last.length());

        string ans = "";

        for(int i=0; i<mini; i++)
        {
            if(one[i]!=last[i])
            {
                return ans;
            }

            ans = ans + one[i];
        }

        return ans;
    }
};