//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&v,int row0,int col0)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||vis[i][j]||grid[i][j]==0) return;
        vis[i][j]=1;
        v.push_back({i-row0,j-col0});
        dfs(i+1,j,grid,vis,v,row0,col0);
        dfs(i-1,j,grid,vis,v,row0,col0);
        dfs(i,j+1,grid,vis,v,row0,col0);
        dfs(i,j-1,grid,vis,v,row0,col0);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,grid,vis,v,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends