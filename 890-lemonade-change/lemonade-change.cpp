class Solution {
public:
    bool lemonadeChange(vector<int>& v) {
        int n = v.size();
        int f1 = 0;
        int f2 = 0;
        int f3 = 0;

        for(int i=0; i<n; i++)
        {
            if(v[i]==5)
            {
                f1++;
                continue;
            }
            else if(v[i]==10)
            {
                if(f1==0)
                {
                    return false;
                }
                f1--;
                f2++;
            }
            else
            {
                if(f2==0 && f1==0)
                {
                    return false;
                }
                if(f2>0 && f1>0)
                {
                    f2--;
                    f1--;
                }
                else if(f1==0)
                {
                    return false;
                }
                else
                {
                    if(f1<3)
                    {
                        return false;
                    }
                    f1-=3;
                }
            }
        }

        return true;
    }
};