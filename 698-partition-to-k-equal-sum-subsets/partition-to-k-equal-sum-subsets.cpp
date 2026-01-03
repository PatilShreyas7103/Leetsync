
class Solution {
public:
    bool solve(int i, int n,
               vector<int> &v,
               vector<int> &side,
               int t, int k) {

        if (i == n) {
            for(int id=0; id<k; id++)
            {
                if(side[id]!=t)
                {
                    return false;
                }
            }

            return true;
        }

        int val = v[i];

        for (int j = 0; j < k; j++) {
            if (side[j] + val > t) continue;

            side[j] += val;
            if (solve(i + 1, n, v, side, t,k)) return true;
            side[j] -= val;

            // symmetry breaking
            if (side[j] == 0) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& v, int k) {
        int n = v.size();
        if (n < k) return false;

        int sum = 0;
        for (int x : v) sum += x;

        if (sum % k != 0) return false;

        int t = sum / k;

        sort(v.rbegin(), v.rend()); // important

        if (v[0] > t) return false;

        vector<int> side(k, 0);
        return solve(0, n, v, side, t,k);
    }
};