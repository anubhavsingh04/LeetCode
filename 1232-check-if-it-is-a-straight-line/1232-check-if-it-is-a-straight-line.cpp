class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n<=1) return false; 
        if(n==2) return true;
        int dy=coordinates[1][1]-coordinates[0][1];
        int dx=coordinates[1][0]-coordinates[0][0];
       
        for(int i=1;i<n;i++)
        {
            int dy1=coordinates[i][1]-coordinates[i-1][1];
            int dx1=coordinates[i][0]-coordinates[i-1][0];
            if(dy1*dx!=dy*dx1) return false;
        }
        return true;
    }
};