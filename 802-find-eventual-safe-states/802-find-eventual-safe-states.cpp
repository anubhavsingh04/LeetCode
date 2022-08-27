class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int vertex,vector<int>&vis,set<int>&safeNode)
    {
          vis[vertex]=1;
         for(auto child:graph[vertex])
         {
              
              if(safeNode.find(child)!=safeNode.end())continue;
              if(vis[child]==1)return false;
              vis[child]=1;
              if(!dfs(graph,child,vis,safeNode))return false ;   
         }
        safeNode.insert(vertex);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        set<int>safeNode;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(graph,i,vis,safeNode);
            }
        }
        vector<int>ans;
        for(auto it:safeNode)ans.push_back(it);
        return ans;
        
    }
};