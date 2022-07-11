// class Solution {
// public:
//     bool bfs(int src,vector<vector<int>>&graph, vector<int>&color)
//     {
//         color[src]=1;
//         queue<int>q;
//         q.push(src);
//         while(!q.empty())
//         {
//             int curr=q.front();
//             q.pop();
//             for(auto &i:graph[curr])
//             {
//                 if(color[i]==-1)
//                 {
//                     color[i]=1-color[curr];
//                     q.push(i);
//                 }
//                 else if(color[i]==color[curr])
//                     return false;
//             }
//         }
//         return true;
//     }
    
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int>color(n,-1);
//         for(int i=0;i<n;i++)
//         {
//             if(color[i]==-1)
//             {
//                 if(!bfs(i,graph,color))
//                     return false;
//             }
//         }
//         return true;
//     }
// };

// Using dfs

class Solution {
public:
    bool dfs(int src,vector<vector<int>>&graph, vector<int>&color)
    {
        if(color[src]==-1)
            color[src]=1;
        for(auto &i:graph[src])
        {
            if(color[i]==-1)
            {
                color[i]=1-color[src];
                if(!dfs(i,graph,color))
                    return false;
            }
            else if(color[i]==color[src])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(i,graph,color))
                    return false;
            }
        }
        return true;
    }
};









// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> colors(n, 0);
//         queue<int> q;
        
//         for (int i = 0; i < n; i++) {
//             if (colors[i]) continue;
            
//             colors[i] = 1;
//             q.push(i);
            
//             while (!q.empty()) {
//                 int temp = q.front();
                
//                 for (auto neighbor : graph[temp]) {
                    
// 					// Color neighbor with opposite color
//                     if (!colors[neighbor]){
//                         colors[neighbor] = -colors[temp];
//                         q.push(neighbor);
//                     }
                    
// 					// If the neighbor has the same color - can't bipartite.
//                     else if (colors[neighbor] == colors[temp]) 
//                         return false;
//                 }
//                 q.pop();
//             }
//         }
//         return true;
//     }
// };