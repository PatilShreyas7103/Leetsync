class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int id = 0;
        int n = v.size();
        for(int i=0; i<n; i++)
        {
            if(v[i]!=val)
            {
                v[id++] = v[i];
            }
        }

        return id;
    }
};