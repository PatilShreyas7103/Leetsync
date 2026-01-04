class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        vector<int> a;
        vector<int> ans;
        int n = v.size();
        for(auto it: v)
        {
            a.push_back(it);
        }
        for(auto it: v)
        {
            a.push_back(it);
        }

        for(int i=0; i<n; i++)
        {
            bool done = false;
            for(int j=i+1; j<2*n-1; j++)
            {
                if(a[j]>a[i])
                {   
                    done = true;
                    ans.push_back(a[j]);
                    break;
                }
            }
            if(!done)
            {
                ans.push_back(-1);
            }

        }

        return ans;

    }
};