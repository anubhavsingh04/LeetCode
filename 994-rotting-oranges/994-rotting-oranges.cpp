class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int time=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        // {{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else 
                {
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            auto  curr=q.front();
            q.pop();
            int row=curr.first.first;
            int col=curr.first.second;
            int t=curr.second;
            time=max(time,t);
            for(int i=0;i<4;i++)
            {
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 &&newrow<n && newcol>=0 && newcol<m
                   && !vis[newrow][newcol] && grid[newrow][newcol]==1)
                {
                    vis[newrow][newcol]=1;
                    q.push({{newrow,newcol},t+1});
                }
            }
        }
        // if any cell remains fresh and we are unable to visit  
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