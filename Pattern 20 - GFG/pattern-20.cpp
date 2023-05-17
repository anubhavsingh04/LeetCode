//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        int k=0,m=2;
        int x=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++) cout<<'*';
            for(int j=0;j<2*(n-i)-2;j++) cout<<' ';
            for(int j=0;j<=i;j++) cout<<'*';
            
            cout<<endl;
        }
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++) cout<<'*';
            for(int j=0;j<2*i+2;j++) cout<<' ';
            for(int j=0;j<n-i-1;j++) cout<<'*';
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends