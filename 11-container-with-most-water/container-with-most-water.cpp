class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();

        int i = 0;
        int j = n-1;
        int ans = 0;

        while(i<=j)
        {
            int res = (j-i)*min(v[i],v[j]);
            ans=max(ans,res);

            if(v[i]<v[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return ans;

    }
};