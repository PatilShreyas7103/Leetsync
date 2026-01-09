class Solution {
public:
    bool check(vector<int>& v) {
        int c = 0;
        int n = v.size();
        if(n==1)
        {
            return 1;
        }
        for(int i=0; i<n-1; i++)
        {   
            if(v[i]>v[i+1])
            {
                c++;
            }
        }   
        if(v[0]<v[n-1])
        {
            c++;
        }

        return c<=1;
    }
};