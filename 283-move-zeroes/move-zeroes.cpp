class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        int id = 0;
        for(int i=0; i<n; i++)
        {
            if(v[i]!=0)
            {
                v[id] = v[i];
                id++;
            }
        }
        for(int i=id; i<n; i++)
        {
            v[i] = 0;
        }
    }
};