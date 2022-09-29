class Solution {
public:
    bool isvalid(int row,int col,vector<string>&grid,int n)
    {
        // left check
        for(int i=0;i<col;i++)
        {
            if(grid[row][i]=='Q') return false;
        }
        // upper left check 
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(grid[i][j]=='Q') return false;
        }
        // lower left check
        for(int i=row,j=col;i<n && j>=0;i++,j--)
        {
            if(grid[i][j]=='Q') return false;
        }
        return true;
    }
    void dfs(int col,vector<vector<string>>&ans,vector<string>&grid,int n)
    {
        if(col==n)
        {
            ans.push_back(grid);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isvalid(row,col,grid,n))
            {
                grid[row][col]='Q';
                dfs(col+1,ans,grid,n);
                grid[row][col]='.'; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>grid(n,string(n,'.'));
        vector<vector<string>>ans;
        int col=0;
        dfs(col,ans,grid,n);
        return ans;
    }
};