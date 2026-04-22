class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        // cosa = sq b + sq c - sq a/ 2bc
        sort(sides.begin(), sides.end());
        if(sides[2] >= sides[0]+sides[1]) return {};

        vector<double> angles(3, 0);
        for(int i=0;i<3;i++)
        {
            int N=0;
            int D=2;
            for(int j=0;j<3;j++)
            {
                N += (i==j) ? -sides[j]*sides[j] : sides[j]*sides[j];
                D *= ( i==j)?1 :sides[j] ; 
            }
            angles[i] = acos(1.0*N/D);
            // in degree
            angles[i] = 180.0*angles[i]/3.141592653589793;
        }
        return angles;

    }
};