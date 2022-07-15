// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // two visited array is needed in directed graph 
    // bool dfs(int src,vector<bool>&vis,vector<bool>&dfsvis, vector<int>adj[])
    // {
    //     vis[src]=true;
    //     dfsvis[src]=true;
    //     for(auto &i:adj[src])
    //     {
    //         if(!vis[i])
    //         {
    //             if(dfs(i,vis,dfsvis,adj))
    //             return true;
    //         }
    //         else if(dfsvis[i])
    //         return true;
    //     }
    //     dfsvis[src]=false;
    //     return false;
    // }
    
    // bool isCyclic(int V, vector<int> adj[]) {
    //     vector<bool>vis(V,false);
    //     vector<bool>dfsvis(V,false);
    //     for(int i=0;i<V;i++)
    //     {
    //         if(!vis[i])
    //         {
    //             if(dfs(i,vis,dfsvis,adj))
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    
    // using kahns algorithm if(we can be able to generate topo(no of nodes in topo sort==V) sort then  graph is acyclic otherwise cyclic )
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto &it:adj[i])
            indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            cnt++;
            for(auto &i:adj[curr])
            {
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }
        if(cnt==V) return false;
        return true;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends