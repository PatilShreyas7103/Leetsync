class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int sz = v.size();
        if(n==0)
        {
            return true;
        }
        // if(sz==1)
        // {
        //     if(n>1)
        //     {
        //         return false;
        //     }
        //     else if(n==1)
        //     {
        //         return v[0]==0;
        //     }
        //     else
        //     {
        //         return true;
        //     }
        // }

        for(int i=0; i<sz; i++)
        {
            if(v[i]==1)
            {
                continue;
            }
            bool safe = 1;
            if(i>0 && v[i-1]==1)
            {
                safe = false;
            }
            if(i<sz-1 && v[i+1]==1)
            {
                safe = false;
            }
            if(safe)
            {
                v[i] = 1;
                n--;
            }
            
            if(n==0)
            {
                return true;
            }
        }

        return false;
    }
};