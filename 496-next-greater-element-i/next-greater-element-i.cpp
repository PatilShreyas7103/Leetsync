class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        for(auto num: a)
        {
            bool f = false;
            bool done = false;
            for(auto val: b)
            {
                if(val==num)
                {
                    f = true;
                }
                if(f && val>num)
                {
                    done = true;
                    ans.push_back(val);
                    break;
                }
            }
            if(!done)
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};