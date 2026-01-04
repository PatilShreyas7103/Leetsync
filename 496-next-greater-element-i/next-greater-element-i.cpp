class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        stack<int> st;
        int n = b.size();

        unordered_map<int,int> mp;
        for(int i=n-1; i>=0 ; i--)
        {
            int val = b[i];
            while(!st.empty() && st.top()<=val)
            {
                st.pop();
            }

            if(st.empty())
            {
                mp[val] = -1;
            }
            else
            {
                mp[val] = st.top();
            }

            st.push(val);
        }

        for(auto num: a)
        {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};