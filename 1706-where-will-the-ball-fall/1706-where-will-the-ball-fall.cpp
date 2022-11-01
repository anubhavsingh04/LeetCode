class Solution {
public:
    int rec(vector<vector<int>>&grid,int curr_row,int curr_col,int n,int m,int dp[101][101])
    {
        if(curr_row==n) return curr_col;
        if(dp[curr_row][curr_col]!=0) {
            return dp[curr_row][curr_col];
        }
        if(grid[curr_row][curr_col]==1) // left to right
        {
            if(curr_col+1>=m || grid[curr_row][curr_col+1]==-1) return -1;
            return dp[curr_row][curr_col]=rec(grid,curr_row+1,curr_col+1,n,m,dp);
        }
        
         if(grid[curr_row][curr_col]==-1) // right to left
        {
            if(curr_col-1<0 || grid[curr_row][curr_col-1]==1) return -1;
            return dp[curr_row][curr_col]=rec(grid,curr_row+1,curr_col-1,n,m,dp);
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>ans;
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        for(int j=0;j<col;j++)
        {
            int x=rec(grid,0,j,row,col,dp);
            ans.push_back(x);
        }
        return ans;
    }
};