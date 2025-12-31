class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int time) {
        mp[key].push_back({value,time});
    }
    
    string get(string key, int time) {
        auto &v = mp[key];
        string ans = "";
        int n = v.size();
        int s = 0;
        int e = n-1;

        while(s<=e)
        {
            int mid = (s+e)/2;
            auto it = v[mid];

            string val = it.first;
            int t = it.second;

            if(t==time)
            {
                ans=val;
                break;
            }
            else if(t>time)
            {
                e = mid-1;
            }
            else
            {
                ans = val;
                s = mid+1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */