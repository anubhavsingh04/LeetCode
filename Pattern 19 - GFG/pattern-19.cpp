//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        int x=0;
        for(int i=0;i<n;i++)
        {
            for(int j=n;j>i;j--)
            {
                cout<<"*";
            }
            for(int i=0;i<x;i++)
            {
                cout<<' ';
            }
            for(int j=n;j>i;j--)
            {
                cout<<"*";
            }
            x+=2;
            cout<<endl;
        }
        x=2*n-2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cout<<"*";
            }
            for(int i=0;i<x;i++)
            {
                cout<<' ';
            }
            for(int j=0;j<=i;j++)
            {
                cout<<"*";
            }
            x-=2;
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