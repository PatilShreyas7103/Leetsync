class Solution {
public:

    int jump(vector<int>& v) {
        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            farthest = max(farthest, i + v[i]);

            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};