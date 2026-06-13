class Solution {
public:
    int majorityElement(vector<int>& v) {
        int count =0;
        int ele = v[0];
        int n = v.size();

        for(int i=0; i<n;i++)
        {
            if(count==0){
                ele = v[i];
            }

            if(v[i]==ele)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return ele;

    }
};