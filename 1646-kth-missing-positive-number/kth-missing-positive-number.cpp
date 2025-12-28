class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        unordered_set<int> st;

        for(auto it: v)
        {
            st.insert(it);
        }
        int ans = 0;

        for(int i=1; i<=k; i++)
        {
            ans++;
            while(st.find(ans)!=st.end())
            {
                ans++;
            }
        }

        return ans;
    }
};