class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        int n = s.size();
        int m = p.size();

        sort(p.begin(), p.end());

        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            long long sp = s[i];
            long long k = (suc+sp-1)/sp;
            int lb = lower_bound(p.begin(), p.end(), k) - p.begin();
            int e = m-lb;
            ans.push_back(e);
        }

        return ans;
    }
};