class Solution {
public:
    #define ll long long 
    void dfs(int src,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[src]=1;
        for(auto i:adj[src]){
            if(!vis[i]) {
                dfs(i,vis,adj);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];
            ll r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j){
                    ll x2=bombs[j][0];
                    ll y2=bombs[j][1];
                    ll r2=bombs[j][2];
                    ll dsq=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
                    if(dsq<=r1*r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            dfs(i,vis,adj);
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(vis[j]) cnt++;
            }
            ans=max(ans,cnt);
            vis=vector<int>(n,0);
        }
        return ans;
    }
};