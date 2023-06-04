class Solution {
public:
    void dfs(int src,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[src]=1;
        for(auto i:adj[src])
        {
            if(!vis[i]) {
                dfs(i,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[0].size();j++)
            {
                if(graph[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};