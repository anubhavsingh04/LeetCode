//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long ans;
    void TOH(int N, int src, int dest, int helper)
    {
        ans++;
        if(N==1) {
            cout<<"move disk "<< N<<" from rod "<<src<<" to rod "<<dest<<endl;
            return;
        }
        
        TOH(N-1,src,helper,dest);
        cout<<"move disk "<< N<<" from rod "<<src<<" to rod "<<dest<<endl;
        TOH(N-1,helper,dest,src);
    }
    long long toh(int N, int from, int to, int aux) {
        ans=0;
        TOH(N,from,to,aux);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends