class Solution {
public:
    int reverseBits(int n) {
        vector<int> ans(32,0);
        int id = 31;
        while(n!=0)
        {
            ans[id] = n&1;
            id--;
            n = n>>1;
        }
        int sum = 0;
        id = 0;
        for(auto it: ans)
        {
            sum+= it*pow(2,id);
            id++;
        }

        return sum;
    }
};