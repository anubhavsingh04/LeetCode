//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack. 
    // sort according to val/wt
    static bool cmp(Item a,Item b)
    {
        return (double)a.value/a.weight>(double)b.value/b.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double profit=0,wt=0;
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(wt+arr[i].weight<=W)
            {
                wt+=arr[i].weight;
                profit+=arr[i].value;
            }
            else 
            {
                int rem=W-wt;
                profit+=(double)rem*((double)arr[i].value/arr[i].weight);
                break;
            }
        }
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends