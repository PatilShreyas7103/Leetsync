class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;

        for(auto it: arr)
        {
            int dis = abs(x-it);
            pq.push({dis,it});

            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            ans.push_back(f.second);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};