class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        if(n==1)
        {
            return 1;
        }
        int id = 1;
        for(int i=2; i<n; i++)
        {
            if(v[id]==v[i])
            {
                if(v[id-1]!=v[id])
                {
                    id++;
                    v[id] = v[i];
                }
            }
            else
            {
                id++;
                v[id] = v[i];
            }
        }

        return id+1;
    }
};