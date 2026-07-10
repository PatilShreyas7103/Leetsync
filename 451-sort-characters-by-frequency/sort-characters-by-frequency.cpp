class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;

        int n = s.length();
        vector<vector<char>> bucket(n + 1);

        for (auto &it : mp) {
            bucket[it.second].push_back(it.first);
        }

        string ans = "";
        for (int f = n; f > 0; f--) {
            for (char c : bucket[f]) {
                ans.append(f, c);
            }
        }

        return ans;
    }
};