class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        vector<int> v(n,0);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]=='1')
                {
                    v[j]++;
                }
                else
                {
                    v[j] = 0;
                }
            }
            int res = largestRectangleArea(v);
            ans=max(ans,res);
     
        }

        return ans;
    }
};