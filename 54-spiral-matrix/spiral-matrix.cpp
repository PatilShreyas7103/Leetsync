class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<int> ans;

        int top = 0;
        int bot = m-1;
        int left = 0;
        int right = n-1;

        while(top<=bot && left<=right)
        {
            for(int i=left; i<=right; i++)
            {
                ans.push_back(v[top][i]);
            }
            top++;

            for(int i=top; i<=bot; i++)
            {
                ans.push_back(v[i][right]);
            }
            right--;
            if(top>bot || left>right)
            {
                break;
            }
            for(int i=right; i>=left; i--)
            {
                ans.push_back(v[bot][i]);
            }
            bot--;
            for(int i=bot; i>=top; i--)
            {
                ans.push_back(v[i][left]);
            }
            left++;
        }

        return ans;
    }
};