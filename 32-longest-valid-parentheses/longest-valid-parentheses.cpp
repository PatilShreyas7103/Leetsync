class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        stack<int> st;
        st.push(-1);
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            if(ch==')')
            {
                st.pop();
                if(!st.empty())
                {
                    int len = i-st.top();
                    ans=max(ans,len);
                }
                else
                {
                    st.push(i);
                }
            }
            else
            {
                st.push(i);
            }
        }

        return ans;
    }
};