class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int m = v.size();
        int n = v[0].size();

        int s = 0;
        int e = n*m-1;

        while(s<=e)
        {
            int mid = (s+e)/2;

            int row = mid/n;
            int col = mid%n;
            int x = v[row][col];

            if(t==x)
            {
                return true;
            }
            else if(t>x)
            {
                s = mid+1;
            }
            else
            {
                e = mid-1;
            }
        }

        return false;
    }
};