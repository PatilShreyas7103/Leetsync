class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        unordered_map<int,int> in;
        unordered_map<int,int> out;

        for(auto it: v)
        {
            int a = it[0];
            int b = it[1];

            out[a]++;
            in[b]++;
        }

        for(int i=1; i<=n;i++)
        {
            if(in[i]==n-1 && out[i]==0)
            {
                return i;
            }
        }

        return -1;
    }
};