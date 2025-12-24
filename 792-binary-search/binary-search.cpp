class Solution {
public:
    int search(vector<int>& v, int t) {
        int n = v.size();

        for(int i=0; i<n; i++)
        {
            if(v[i]==t)
            {
                return i;
            }
        }

        return -1;
    }
};