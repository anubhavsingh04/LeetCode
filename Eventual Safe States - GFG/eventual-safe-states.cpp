//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int src,vector<int>&vis,vector<int>&pathvis,vector<int>&safe,vector<int>adj[]){
        vis[src]=1;
        pathvis[src]=1;
        for(auto &i:adj[src]){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,safe,adj)) return true;
            }
            else if(vis[i] && pathvis[i]) return true;
        }
        pathvis[src]=false;
        safe[src]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int n=V;
        vector<int>vis(n+1,0),pathvis(n+1,0);
        vector<int>safe(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,safe,adj);
            }
        }
       
        vector<int>ans;
        for(int i=0;i<n;i++) {
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends