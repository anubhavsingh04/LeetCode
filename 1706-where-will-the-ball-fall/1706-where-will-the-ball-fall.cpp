class Solution {
public:
    int rec(vector<vector<int>>&grid,int curr_row,int curr_col,int n,int m)
    {
        if(curr_row==n) return curr_col;
        if(grid[curr_row][curr_col]==1) // left to right
        {
            if(curr_col+1>=m || grid[curr_row][curr_col+1]==-1) return -1;
            return rec(grid,curr_row+1,curr_col+1,n,m);
        }
        
         if(grid[curr_row][curr_col]==-1) // right to left
        {
            if(curr_col-1<0 || grid[curr_row][curr_col-1]==1) return -1;
            return rec(grid,curr_row+1,curr_col-1,n,m);
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>ans;
        for(int j=0;j<col;j++)
        {
            int x=rec(grid,0,j,row,col);
            ans.push_back(x);
        }
        return ans;
    }
};