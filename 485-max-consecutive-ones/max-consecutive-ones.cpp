class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& v) {
        int len = 0;
        int ans = 0;
        for(auto it: v)
        {
            if(it==1)
            {
                len++;
                ans=max(ans,len);
            }
            else
            {
                ans=max(ans,len);
                len = 0;
            }
        }

        return ans;
    }
};