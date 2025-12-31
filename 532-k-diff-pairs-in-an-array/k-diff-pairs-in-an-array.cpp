class Solution {
public:
    int findPairs(vector<int>& v, int x) {
        int n = v.size();
        sort(v.begin(), v.end());
        int ans = 0;

        int i = 0, j = 1;
        while (i < n && j < n) {
            if (i == j) {
                j++;
                continue;
            }
            if(i!=0)
            {
                if(v[i]==v[i-1] && v[j]==v[j-1])
                {
                    i++;
                    j++;
                    continue;
                }
            }
            int diff = v[j] - v[i];

            if (diff == x)
            {
                ans++;
                i++;
                j++;
            } 
            else if (diff < x) j++;
            else i++;
        }
        return ans;
    }
};