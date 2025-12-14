class Solution {
public:
    int solve(int i, vector<int> &g, int j, vector<int> &s)
    {
        if(i<0 || j<0)
        {
            return 0;
        }

        if(g[i]<=s[j])
        {
            return 1+solve(i-1,g,j-1,s);
        }
        else
        {
            return solve(i-1,g,j,s);
        }
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        return solve(m-1,g,n-1,s);
    }
};