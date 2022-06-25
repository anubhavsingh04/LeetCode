// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[],int n,int idx,string op,vector<string>&ans,unordered_map<int,string>&m)
    {
        if(idx>=n)
        {
            ans.push_back(op);
            return;
        }
        string s=m[a[idx]];
        for(int i=0;i<s.size();i++)
        {
            op.push_back(s[i]);
            solve(a,n,idx+1,op,ans,m);
            op.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        unordered_map<int,string>m={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},
                          {6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
                          string op="";
                          vector<string>ans;
                          int idx=0;
                          solve(a,N,idx,op,ans,m);
                          return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends