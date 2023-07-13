class Solution {
public:
    bool dfs(int src,vector<vector<int>>&adj,vector<int>&vis)
    {
        if(vis[src]==1) return true;
        if(vis[src]==0){
            vis[src]=1;
            for(auto &i:adj[src])
            {
                if(dfs(i,adj,vis)==true) return true;
            }
        }
        vis[src]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        vector<vector<int>>adj(numCourses);
        for(auto &i:nums)
        {
            adj[i[0]].push_back(i[1]);
        }
        vector<int>vis(numCourses+1,0);
        for(int i=0;i<numCourses;i++)
        {
            if(dfs(i,adj,vis)) return false;
        }
        return true;
    }
};