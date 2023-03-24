class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n),adj2(n);
        for(auto &i:connections){
            adj[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        int ans=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(auto &i:adj[curr]){
                if(!vis[i]){
                    ans++;
                    q.push(i);
                }
            }
            for(auto &i:adj2[curr]){ // edges which are already towards 0 
                if(!vis[i]){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};