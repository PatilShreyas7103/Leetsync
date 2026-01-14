class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g = 0, c = 0;
        for (int i = 0; i < gas.size(); i++) {
            g += gas[i];
            c += cost[i];
        }

        if (g < c) {
            return -1;
        }

        int curr = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            curr += gas[i] - cost[i];
            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
        }

        return start;        
    }
};