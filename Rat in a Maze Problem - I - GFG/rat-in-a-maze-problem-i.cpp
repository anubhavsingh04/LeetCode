// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool issafe(int x,int y,vector<vector<int>>&m,vector<vector<int>>vis,int n)
    {
        if((x>=0&&x<n) && (y>=0&&y<n) && vis[x][y]==0 && m[x][y]==1) 
        return true;
        else 
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n,vector<string> &ans,int x,int y,
    vector<vector<int>> vis,string path)
    {
        if(x==n-1&&y==n-1)
        {
            ans.push_back(path);
            return;
        }
        vis[x][y]=1;
        // down 
        int newx=x+1;
        int newy=y;
        if(issafe(newx,newy,m,vis,n))
        {
            path.push_back('D');
            solve(m,n,ans,newx,newy,vis,path);
            path.pop_back();
        }
        
         // left 
         newx=x;
         newy=y-1;
        if(issafe(newx,newy,m,vis,n))
        {
            path.push_back('L');
            solve(m,n,ans,newx,newy,vis,path);
            path.pop_back();
        }
        
         // up 
         newx=x-1;
         newy=y;
        if(issafe(newx,newy,m,vis,n))
        {
            path.push_back('U');
            solve(m,n,ans,newx,newy,vis,path);
            path.pop_back();
        }
        
         // right move 
        newx=x;
        newy=y+1;
        if(issafe(newx,newy,m,vis,n))
        {
            path.push_back('R');
            solve(m,n,ans,newx,newy,vis,path);
            path.pop_back();
        }
        vis[x][y]=0; 
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
         vector<string>ans;
         int srcx=0,srcy=0;
         if(m[0][0]==0)
         return ans;
         vector<vector<int>>vis=m;
         // initialise visited matrix with 0
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 vis[i][j]=0;
             }
         }
         string path="";
         solve(m,n,ans,srcx,srcy,vis,path);
         sort(ans.begin(),ans.end());
         return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends