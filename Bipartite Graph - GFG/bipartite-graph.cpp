// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    // bool bfs(int src,vector<int>adj[],vector<int>&color)
    // {
    //     color[src]=1;
    //     queue<int>q;
    //     q.push(src);
    //     while(!q.empty())
    //     {
    //         int curr=q.front();
    //         q.pop();
    //         for(auto &i:adj[curr])
    //         {
    //             if(color[i]==-1)
    //             {
    //                 color[i]=1-color[curr];
    //                 q.push(i);
    //             }
    //             else if(color[i]==color[curr])
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    
    bool dfs(int src,vector<int>adj[],vector<int>&color)
    {
        if(color[src]==-1)
        color[src]=1;
        for(auto &i:adj[src])
        {
            if(color[i]==-1)
            {
                color[i]=1-color[src];
                if(!dfs(i,adj,color))
                return false;
            }
            else if(color[i]==color[src])
            return false;
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!dfs(i,adj,color))
	            return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends