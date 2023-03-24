class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<vector<int>>& adj,int &ans){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[abs(x)]){
                if(x>0)
                ans++;
                dfs(abs(x),vis,adj,ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        vector<int>vis(n,0);
        int ans=0;
        dfs(0,vis,adj,ans);
        return ans;
    }
};