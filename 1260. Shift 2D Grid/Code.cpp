class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid[0].size();
        long long int n=grid.size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
// if k is 1 new column is j+1 likewise if k is k new column is j+k in range of 
// 0 to m-1
// no of rows added = no of times j+k exceeds m i.e. (j+k)/m so new row = (i+(j+k)/m)%n
                int newJ=(j+k)%m;
                int newI=(i+(j+k)/m)%n;
                ans[newI][newJ]=grid[i][j];
            }
        }
        return ans ;
    }
};