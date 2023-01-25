class Solution {
public:
    void dfs(int node,vector<int>&dist1,vector<int>&edges,vector<int>&vis,int distance)
    {
        if(node!=-1 && !vis[node]){
            vis[node]=1;
            dist1[node]=distance;
            dfs(edges[node],dist1,edges,vis,distance+1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,-1),dist2(n,-1),vis(n,0);
        dfs(node1,dist1,edges,vis,0);
        vis.assign(n,0);
        dfs(node2,dist2,edges,vis,0);
        int ans=-1,mini=n;
        for(int i=0;i<n;i++)
        {
            if(dist1[i]!=-1 && dist2[i]!=-1) // if node i is reacheable from both node1 and node2
            {
                if(max(dist1[i],dist2[i])<mini){
                    mini=max(dist1[i],dist2[i]);
                    ans=i;
                }   
            }
        }
        return ans;
    }
};