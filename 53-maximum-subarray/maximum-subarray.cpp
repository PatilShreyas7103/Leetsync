class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        int ans = INT_MIN;

        for(auto it: v)
        {
            if(sum<0)
            {
                sum = 0;
            }
            sum+=it;
            ans=max(ans,sum);
        }   

        return ans;
    }
};