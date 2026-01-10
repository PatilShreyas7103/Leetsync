class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int len = 1;
        int ans = 1;
        if(n==0 || n==1)
        {
            return n;
        }

        for(int i=0; i<n-1; i++)
        {
            if(v[i]+1==v[i+1])
            {
                len++;
                ans=max(ans,len);
            }
            else if(v[i]==v[i+1])
            {
                continue;
            }
            else
            {
                len = 1;
            }
        }

        return ans;
    }
};