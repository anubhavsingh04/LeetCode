class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; // {{row,col},time}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        // apply bfs 
        // new row and newcol should be in boundary not visited and grid of i j should be 1
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int row=curr.first.first;
            int col=curr.first.second;
            int t=curr.second;
            time=max(time,t);
            for(int i=0;i<4;i++)
            {
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && 
                grid[newrow][newcol]==1 && !vis[newrow][newcol])
                {
                    q.push({{newrow,newcol},t+1});
                    vis[newrow][newcol]=2;
                }
            }
        }
        // check if there is any fresh cell remainig then return -1
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};