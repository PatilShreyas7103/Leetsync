class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
 
        vector<vector<int>> ans(n,vector<int> (n,0));

        int top = 0;
        int bot = n-1;
        int left = 0;
        int num = 1;
        int right = n-1;

        while(top<=bot && left<=right)
        {
            for(int i=left; i<=right; i++)
            {
                ans[top][i] = num;
                num++;
            }
            top++;

            for(int i=top; i<=bot; i++)
            {
                ans[i][right] = num;
                num++;
            }
            right--;
            if(top>bot || left>right)
            {
                break;
            }
            for(int i=right; i>=left; i--)
            {
                ans[bot][i] = num;
                num++;
            }
            bot--;
            for(int i=bot; i>=top; i--)
            {
                ans[i][left] = num;
                num++;
            }
            left++;
        }

        return ans;
    }
};