class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        vector<int> b;
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(auto it: v)
        {
            b.push_back(it);
        }
        for(auto it: v)
        {
            b.push_back(it);
        }

        for(int i = b.size() - 1; i >= 0; i--) {
            int val = b[i];
            while(!st.empty() && st.top() <= val) {
                st.pop();
            }
            if(i<n)
            {
                ans[i] = st.empty() ? -1 : st.top();
            }
            
            st.push(val);
        }

        return ans;
    }
};