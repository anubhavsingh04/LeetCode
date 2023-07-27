//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    
    public:
    //Function to merge k sorted arrays.
    typedef pair<int,pair<int,int>> ppi;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>indices(K,0);
        vector<int>ans;
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        for(int i=0;i<K;i++) pq.push({arr[i][0],{i,0}});
        
        while(not pq.empty()) {
            ans.push_back(pq.top().first);
            pair<int,int>temp=pq.top().second;
            temp.second++;
            pq.pop();
            if(temp.second<arr[temp.first].size())
            pq.push({arr[temp.first][temp.second],temp});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends