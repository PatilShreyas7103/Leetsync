class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        int dep = 0;

        for(auto it: s)
        {
            if(it=='(')
            {
                dep++;
                ans=max(ans,dep);
            }
            else if(it==')')
            {
                dep--;
            }
        }

        return ans;
    }
};