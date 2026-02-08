class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& v) {
        int n = v.size();

        stack<long long> st;
        for(auto it: v)
        {
            if(!st.empty() && it==st.top())
            {
                st.pop();
                long long curr = 2*it;
                while(!st.empty() && curr==st.top())
                {
                    curr = (long long)2*st.top();
                    st.pop();
                }
                st.push(curr);
            }
            else
            {
                st.push(it);
            }
        }

        vector<long long> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};