class Solution {
public:

    int rob(vector<int>& v) {
        int n = v.size();

        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return v[0];
        }
        if(n==2)
        {
            return max(v[0], v[1]);
        }
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);

        vector<int> v1,v2;
        for(int i=0; i<n-1; i++)
        {
            v1.push_back(v[i]);
        }
        for(int i=1; i<n; i++)
        {
            v2.push_back(v[i]);
        }

        dp1[0] = v1[0];
        dp2[0] = v2[0];
        dp1[1] = max(v1[0], v1[1]);
        dp2[1] = max(v2[0], v2[1]);

        for(int i=2; i<n-1; i++)
        {
            int take1 = v1[i]+dp1[i-2];
            int dont1 = dp1[i-1];
            dp1[i] = max(take1,dont1);

            int take2 = v2[i]+dp2[i-2];
            int dont2 = dp2[i-1];
            dp2[i] = max(take2,dont2);
        }

        return max(dp1[n-2], dp2[n-2]);
    }
};