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
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
                int curr_idx=i;
                int good=0;
                while(dp[curr_idx]!=1)
                {
                    dp[curr_idx]=1;
                    if(arr[curr_idx]==0) break;
                    curr_idx=curr_idx+arr[curr_idx];
                    if(curr_idx<0 || curr_idx>n-1 || dp[curr_idx]==2)
                    {
                        good=1;
                        break;
                    }
                }
                if(good)
                {
                    int tmp=i;
                    while(tmp>=0 && tmp<n)
                    {
                        dp[tmp]=2;
                        tmp+=arr[tmp];
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==2) ans++;
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