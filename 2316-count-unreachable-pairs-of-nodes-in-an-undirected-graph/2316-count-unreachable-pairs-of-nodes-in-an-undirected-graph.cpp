class Solution {
public:
    void dfs(int src,vector<int>&vis,long long &cnt,vector<vector<int>>&adj)
    {
        vis[src]=1;
        cnt++;
        for(auto &i:adj[src]){
            if(!vis[i]){
                dfs(i,vis,cnt,adj);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n);
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long ans=(long long)n*((long long)n+1)/2;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                long long cnt=0;
                dfs(i,vis,cnt,adj);
                ans-=(long long)cnt*((long long)cnt+1)/2;
            }
        }
        return ans;
    }
};