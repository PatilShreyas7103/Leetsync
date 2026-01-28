class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();

        vector<int> ans(n,1);
        
        for(int i=1; i<n; i++)
        {
            if(v[i]>v[i-1])
            {
                ans[i]=ans[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--)
        {
            if(v[i]>v[i+1])
            {
                ans[i]=max(ans[i],ans[i+1]+1);
            }
        }
        

        int sum = 0;
        for(auto it: ans)
        {
            sum+= it;
        }

        return sum;
        
    }
};