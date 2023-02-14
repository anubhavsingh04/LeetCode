//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void dfs(vector<vector<int>>&height,vector<vector<int>>&ocean,int i,int j,int n,int m)
    {
        if(i<0 || i>n-1 || j<0 || j>m-1 ) return ;
        if(!ocean[i][j])
        {
            ocean[i][j]=1;
            if(i-1>=0 && height[i-1][j]>=height[i][j]) dfs(height,ocean,i-1,j,n,m);
            if(i+1<n && height[i+1][j]>=height[i][j]) dfs(height,ocean,i+1,j,n,m);
            if(j-1>=0 && height[i][j-1]>=height[i][j]) dfs(height,ocean,i,j-1,n,m);
            if(j+1<m && height[i][j+1]>=height[i][j]) dfs(height,ocean,i,j+1,n,m);
        }
    }
    int water_flow(vector<vector<int>> &grid,int n,int m){
        vector<vector<int>>indian(n,vector<int>(m,0));
        vector<vector<int>>arabian(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0)
                {
                    if(!indian[i][j]) dfs(grid,indian,i,j,n,m);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1||j==m-1)
                {
                    if(!arabian[i][j]) dfs(grid,arabian,i,j,n,m);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(indian[i][j] && arabian[i][j]) ans++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends