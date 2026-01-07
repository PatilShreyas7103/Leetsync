class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push_back(t);
        int cnt = 0;
        int n = v.size();
        for(int i=n-1; i>=0; i--)
        {
            if(v[i]>=t-3000)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }

        return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */