class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> ans;
        map<int,int> id;
        for(int i=0; i<n; i++)
        {
            id[s[i]] = i;
        }  
        int i = 0;
        int j = 0;
        int f = -1;

        while(j<n)
        {
            f = max(f, id[s[j]]);
            if(f==j)
            {
                ans.push_back(j-i+1);
                i = j+1;
                j = i;
                f = -1;
            }
            else
            {
                j++;
            }
        }     

        return ans;
    }
};