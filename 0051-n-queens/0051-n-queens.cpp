class Solution {
public:
    bool isvalid(int row,int col,vector<string>&grid)
    {
        // left check
        for(int i=col;i>=0;i--){
            if(grid[row][i]=='Q') return false;
        }
        // upper left 
        int x=row,y=col;
        while(x>=0 && y>=0){
            if(grid[x][y]=='Q') return false;
            x--;
            y--;
        }
        // lower left
        x=row,y=col;
        while(x< grid.size()&& y>=0){
            if(grid[x][y]=='Q') return false;
            x++;
            y--;
        }
        return true;
    }
    void rec(int col,int n,vector<string>&grid,vector<vector<string>>&ans)
    {
        if(col>=n) {
            ans.push_back(grid);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isvalid(row,col,grid)){
                grid[row][col]='Q';
                rec(col+1,n,grid,ans);
                grid[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>grid(n,string(n,'.'));
        vector<vector<string>>ans;
        rec(0,n,grid,ans);
        return ans;
    }
};