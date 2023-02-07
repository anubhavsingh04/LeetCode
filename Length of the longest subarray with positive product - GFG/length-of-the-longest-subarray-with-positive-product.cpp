//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        
        int maxLength(vector<int> &arr,int n){
           int i=0;
           int ans=0;
           while(i<n)
           {
               int start=i,end;
               while(start<n&&arr[start]==0) start++;
               end=start;
               int negcnt=0,firstneg=-1,lastneg=-1;
               while(end<n && arr[end]!=0)
               {
                   if(arr[end]<0)
                   {
                       negcnt++;
                       if(firstneg==-1) firstneg=end;
                       lastneg=end;
                   }
                   end++;
               }
               if(negcnt%2==0) ans=max(ans,end-start);
               else {
                   if(firstneg!=-1) ans=max(ans,end-firstneg-1); // ignore first neg
                   if(lastneg!=-1) ans=max(ans,lastneg-start); // ignore lastneg
                //   cout<<end<<" "<<firstneg<<" "<<lastneg<<endl;
               }
               i=end+1;
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends