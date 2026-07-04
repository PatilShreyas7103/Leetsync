class Solution {
public:
    bool valid(int r, int c, int n){
        return (r<n && c<n && r>=0 && c>=0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> dis(n, vector<int> (n,INT_MAX));

        if(v[0][0]==1 || v[n-1][n-1]==1)
        {
            return -1;
        }
        using P = pair<int,pair<int,int>> ;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({1,{0,0}});
        dis[0][0] = 1;

        int dx[] = {-1,0,1,0,-1,1,1,-1};
        int dy[] = {0,1,0,-1,-1,1,-1,1};

        while(!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            int d = t.first;
            int row = t.second.first;
            int col = t.second.second;

            if(row==n-1 && col==n-1)
            {
                return d;
            }

            for(int i=0; i<8; i++)
            {
                int adjr = row+dx[i];
                int adjc = col+dy[i];

                if(valid(adjr,adjc,n) && v[adjr][adjc]==0)
                {
                    if(1+d<dis[adjr][adjc])
                    {
                        dis[adjr][adjc] = 1+d;
                        pq.push({dis[adjr][adjc], {adjr,adjc}});
                    }
                }
            }
        }

        return -1;
    }
};