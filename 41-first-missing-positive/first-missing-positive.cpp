class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n = v.size();
        set<int> st;
        int mx = 0;
        for(auto it: v)
        {
            mx = max(mx,it);
            st.insert(it);
        }
        int ans = -1;

        for(int i=1; i<=mx; i++)
        {
            if(st.count(i)==0)
            {
                ans =  i;
                break;
            }
        }

        return ans==-1 ? mx+1 : ans;
    }
};