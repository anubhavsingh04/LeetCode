//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int nums[] ,int N) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int count_zero=0,count_one=0;
            for(int j=0;j<N;j++)
            {
                if((1<<i)&nums[j]) count_one++; // checking jth bit is set or not
                else count_zero++;
            }
            if(count_one%3==1) { //if count of 1 is not divisoble by 3 means our current bit is 1
                ans=ans|(1<<i);
            } 
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends