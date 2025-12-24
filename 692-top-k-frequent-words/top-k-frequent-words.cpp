
class Solution {
public:
    struct Compare {
        bool operator()(const pair<string,int>& a,
                        const pair<string,int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (string& word : words) {
            freq[word]++;
        }

        priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            Compare
        > minHeap;

        for (auto& it : freq) {
            minHeap.push({it.first, it.second});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = minHeap.top().first;
            minHeap.pop();
        }

        return ans;
    }
};