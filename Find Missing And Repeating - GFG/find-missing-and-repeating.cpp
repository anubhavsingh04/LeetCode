//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> A, int n) {
       
        int xr=0;
        for(int i=0;i<n;i++){
            xr^=A[i];
            xr^=(i+1);
        }
        int bitno=0;
        while(true){
            if((1<<bitno)&xr) break;
            bitno++;
        }
        int zero=0,one=0;
        for(int i=0;i<n;i++){
            if((1<<bitno)&A[i]){
                one^=A[i];
            }
            else {
                zero^=A[i];
            }
            if((1<<bitno)&(i+1)){
                one^=(i+1);
            }
            else {
                zero^=(i+1);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(A[i]==one){
                cnt++;
            }
        }
        if(cnt==2) return {one,zero};
        else return {zero,one};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends