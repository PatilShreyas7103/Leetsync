class Solution {
public:
    int compress(vector<char>& v) {
        int n = v.size();

        int i = 0;
        int j = 0;
        int id = 0;

        while(j<n)
        {
            while(j<n && v[j]==v[i])
            {
                j++;
            }
            int cnt = j-i;
            v[id++] = v[i];
            if(cnt!=1)
            {
                string temp = "";

                while(cnt>0)
                {
                    int d = cnt%10;
                    cnt/=10;
                    temp+=d+'0';
                }
                for(int k=temp.size()-1; k>=0; k--)
                {
                    v[id++] = temp[k];
                }
            }
            i = j;
        }

        return id;
    }
};