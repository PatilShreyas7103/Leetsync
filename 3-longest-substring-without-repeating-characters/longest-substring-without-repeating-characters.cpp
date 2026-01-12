class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            int len = 0;
            unordered_set<char> st;
            for(int j=i; j<n; j++)
            {
                if(st.count(s[j])==0)
                {
                    len++;
                    ans=max(ans,len);
                    st.insert(s[j]);
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }
};