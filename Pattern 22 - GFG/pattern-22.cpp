//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
//   print in reverse order and then substract forn n to get values 
// value of each cell csn be determined as min({distance from top,left,bottom,down})

    void printSquare(int n) {
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<2*n-1;j++)
            {
                cout<<n-min({i,2*n-2-i,j,2*n-2-j})<<' ';
            }
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends