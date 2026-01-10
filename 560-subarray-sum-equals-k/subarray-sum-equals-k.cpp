class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int n = v.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int s = 0;
        int cnt = 0;
        for(int i=0;i<n; i++)
        {
            s+= v[i];
            int r = s-k;
            cnt+= mp[r];
            mp[s]++;
        }

        return cnt;
    }
};