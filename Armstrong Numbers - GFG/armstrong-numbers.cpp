//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int cube(int n)
  {
      return n*n*n;
  }
    string armstrongNumber(int n){
        int n1=n,sum=0;
        while(n1>0)
        {
            int rem=n1%10;
            sum+=cube(rem);
            n1/=10;
        }
        if(sum==n) return "Yes";
        else return "No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends