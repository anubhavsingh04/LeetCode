class Solution {
public:
    int dfs(int src,vector<int>adj[],vector<int>&vis,unordered_set<int>&s)
    {
        int cnt=0;
        if(!vis[src])
        {
            vis[src]=1;
            cnt++;
        }
        for(auto &i:adj[src])
        if(!vis[i] && !s.count(i)) 
            cnt+=dfs(i,adj,vis,s);
        return cnt;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>s(restricted.begin(),restricted.end());
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=dfs(0,adj,vis,s);
        return ans;
    }
};

// Using bfs
// class Solution {
// public:
//     int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
//         unordered_set<int>s(restricted.begin(),restricted.end());
//         vector<int>vis(n,0);
//         int ans=0;
//         vector<int>adj[n];
//         for(int i=0;i<edges.size();i++)
//         {
//             int u=edges[i][0];
//             int v=edges[i][1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         queue<int>q;
//         q.push(0);
//         vis[0]=true;
//         while(!q.empty())
//         {
//             int curr=q.front();
//             q.pop();
//             if(s.count(curr)) continue;
//             ans++;
//             for(auto &i:adj[curr])
//             {
//                 if(!vis[i])
//                 {
//                     vis[i]=true;
//                     q.push(i);
//                 }
//             }
//         }
//         return ans;
//     }
// };