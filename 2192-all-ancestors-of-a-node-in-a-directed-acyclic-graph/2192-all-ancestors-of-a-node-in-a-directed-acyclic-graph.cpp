class Solution {
public:
    void dfs(int src,int i,vector<int>&vis,vector<vector<int>>&adj,vector<vector<int>>&ans){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]) {
                ans[x].push_back(src);
                dfs(src,x,vis,adj,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,i,vis,adj,ans);
        }
        return ans;
        
    }
};