class Solution {
public:
    int solve(int i, int j, int k, string &s1, string &s2, string &s3,
    int x, int y, int z, vector<vector<vector<int>>> &dp)
    {
        if(k==z)
        {
            if(i==x && j==y)
            {
                // all end
                return true;
            }
            else
            {
                return false;
            }
        }

        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }

        // both, one, none
        char a = s1[i];
        char b = s2[j];
        char c = s3[k];

        if(i<x && j<y && a==c && b==c)
        {
            return dp[i][j][k]= (solve(i+1,j,k+1,s1,s2,s3,x,y,z,dp) || solve(i,j+1,k+1,s1,s2,s3,x,y,z,dp));
        }
        else if(i<x && a==c)
        {
            return dp[i][j][k]= solve(i+1,j,k+1,s1,s2,s3,x,y,z,dp);
        }
        else if(j<y && b==c)
        {
            return dp[i][j][k]= solve(i,j+1,k+1,s1,s2,s3,x,y,z,dp);
        }
        else
        {
            return dp[i][j][k]= false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int x = s1.length();
        int y = s2.length();
        int z = s3.length();

        vector<vector<vector<int>>> dp(x+1, vector<vector<int>> (y+1, vector<int> (z+1,-1)));

        return solve(0,0,0,s1,s2,s3,x,y,z,dp);
    }
};