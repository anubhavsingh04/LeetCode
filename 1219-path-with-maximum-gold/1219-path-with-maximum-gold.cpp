class Solution {
public:
    int dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        if(i<0 ||i>=n || j<0 || j>=m || vis[i][j] || grid[i][j]==0)
            return 0;
        vis[i][j]=1;
        
        int x=dfs(i+1,j,n,m,grid,vis);
        int y=dfs(i-1,j,n,m,grid,vis);
        int z=dfs(i,j+1,n,m,grid,vis);
        int w=dfs(i,j-1,n,m,grid,vis);
        vis[i][j]=0;
        return grid[i][j]+max({x,y,z,w});
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                    ans=max(ans,dfs(i,j,n,m,grid,vis));
            }
        }
        return ans;
    }
};