class Solution {
public:
    int dominantIndices(vector<int>& v) {
        int n = v.size();
        int cnt = 0;
        for(int i=0; i<n-1; i++)
        {
            double sum = 0;
            for(int j=i+1; j<n; j++)
            {
                sum+= v[j];
            }

            int avg = sum/(n-1-i);
            if(v[i]>avg)
            {
                cnt++;
            }
        }

        return cnt;
    }
};