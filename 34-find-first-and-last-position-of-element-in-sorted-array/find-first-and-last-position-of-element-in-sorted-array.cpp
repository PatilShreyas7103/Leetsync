class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        int n = v.size();
        int start = -1;
        int end = -1;

        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(v[i]==t)
            {
                if(start==-1)
                {
                    start = i;
                }
                end = i;
            }
            else if(v[i]>t)
            {
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};