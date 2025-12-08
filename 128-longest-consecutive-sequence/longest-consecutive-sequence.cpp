class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        int n = v.size();
        if(n==0 || n==1)
        {
            return n;
        }
        int len = 0;
        int mx = 0;
        set<int> st;
        for(auto it: v)
        {
            st.insert(it);
        }
        int prev = *st.begin();

        for(auto it : st)
        {
            if(it-prev==1)
            {
                len++;
                mx = max(mx, len);
            }
            else
            {
                len = 0;
            }
            prev = it;
        }

        return mx+1;
    }
};