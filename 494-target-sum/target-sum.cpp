class Solution {
public:
    int solve(int i, int t, vector<int> &v)
    {
        if(i<0)
        {
            return t==0;
        }

        int pos = solve(i-1,t-v[i],v);
        int neg = solve(i-1,t+v[i],v);

        return neg+pos;
    }
    int findTargetSumWays(vector<int>& v, int t) {
        int n = v.size();

        return solve(n-1,t,v);
    }
};