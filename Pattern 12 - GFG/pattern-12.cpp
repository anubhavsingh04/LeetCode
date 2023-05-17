//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++) cout<<j+1<<" ";
            
        for(int x=0;x<2*(n-i)-2;x++) {
            cout<<"  ";
        }
            for(int j=i;j>=0;j--) cout<<j+1<<" ";
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