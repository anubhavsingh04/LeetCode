//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> geek) {
        if(n<=k) return geek[n-1];
        vector<long long>v(n);
        long long sum=0;
        for(int i=0;i<k;i++)
        {
            v[i]=geek[i];
            sum+=geek[i];
            //  cout<<"*"<<endl;
        }
        long long start=0;
        for(int i=k;i<n;i++)
        {
           
            v[i]=sum;
            sum+=v[i];
            sum-=v[start++];
        }
        return v[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends