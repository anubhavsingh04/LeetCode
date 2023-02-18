//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    // 0 means not visited 
    // 1 means bad index 
    // 2 means good index 
    int goodStones(int n,vector<int> &arr){
    vector<int>vis(n,0);
     for(int i = 0;i<n;i++)
     {
         if(vis[i]==0)
         {
             int curr = i;
             int good=0;
             while(vis[curr]!=1)
             {
                 
                 vis[curr] = 1;
                 if(arr[curr] == 0) break;
                 curr += arr[curr];
                 if(curr<0 || curr>n-1 || vis[curr]==2)
                 {
                     good=1;
                     break;
                 }
             }
             if(good)
             {
                 int  temp = i;
                 while( temp >= 0 && temp < n)
                 {
                   vis[temp] = 2;
                   temp +=arr[temp];
                 }
             }
         }
     }
     int ans = 0;
     for(int i = 0;i<n;i++)
     {
         if(vis[i] == 2)
         {
             ans++;
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends