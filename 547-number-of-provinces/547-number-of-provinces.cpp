class Solution {
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        if(!vis[node]) vis[node]=1;
        for(auto &i:adj[node])
        {
            if(!vis[i])
                dfs(i,adj,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};