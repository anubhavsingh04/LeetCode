//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // watch sumeet malik video 
    // most optmized is get the max power of 2 in less or equal to n 
    // number of bits till x-1 will be x*2^(x-1)
    // and msb bits form 2powx to n will be n-2powx+1
    // remaining number will be n-2pow x
    int getmaxpowerof2(int n){
        int x=0;
        while((1<<x)<=n) {
            x++;
        }
        return x-1;
    }
    int countBits(int n){
        if(n==0) return 0;
        int x=getmaxpowerof2(n);
        int bittill2powx=x*(1<<(x-1));
        int msbbitsfrom2powxton=n-(1<<x)+1;
        int remain=n-(1<<x);
        int ans=bittill2powx+msbbitsfrom2powxton+countBits(remain);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends