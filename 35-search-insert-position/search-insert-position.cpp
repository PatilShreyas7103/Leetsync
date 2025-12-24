class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        int n = v.size();
        
        int ans = 0 ;
        for(int i=0; i<n; i++)
        {
            if(v[i]>t)
            {
                break;
            }
            else if(v[i]==t)
            {
                return i;
            }
            else
            {
                ans=i+1;
            }
        }

        return ans;
    }
};