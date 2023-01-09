//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool ispalindrome(int n)
    {
       int tmp=n;
       int rev=0;
       while(tmp>0)
       {
           rev=rev*10+tmp%10;
           tmp/=10;
       }
       return n==rev;
    }
    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++)
    	{
    	    if(!ispalindrome(a[i])) return 0;
    	}
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends