class Solution {
public:
    int solve(int s, int e, vector<int> &v, int t)
    {
        if(s>e)
        {
            return -1;
        }

        int mid = (s+e)/2;
        if(v[mid]==t)
        {
            return mid;
        }
        else if(t>v[mid])
        {
            return solve(mid+1,e,v,t);
        }
        else
        {
            return solve(s,mid-1,v,t);
        }
    }
    int search(vector<int>& v, int t) {
        int n = v.size();
        int s = 0;
        int e = n-1;

        int ans = solve(s,e,v,t);
        return ans;
    }
};