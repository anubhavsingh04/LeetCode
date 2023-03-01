//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int b_search(int nums[],int l,int r,int key)
    {
        int start=l;
        int end=r;
        while(start<=end)
        {
            int mid=(start+(end-start)/2);
            if(nums[mid]==key) return mid;
            else if(key<nums[mid]) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    int search(int nums[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        int idx=-1;
        int n=h-l+1;
        int start=l,end=h;
        if(nums[l]<=nums[h]){
            return b_search(nums,l,h,key);
        }
        else 
        {
            while(start<=end)
            {
                if(nums[start]<=nums[end]) {
                    idx=start;
                    break;
                }
                int mid=(start+(end-start)/2);
                int prev=(mid-1+n)%n;
                int next=(mid+1)%n;
    
                if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]) {
                    idx=mid;
                    break;
                }
                else if(nums[start]<=nums[mid]) { 
                    start=mid+1;
                }
                else {
                    end=mid-1;
                }
            }
        }
        // cout<<idx<<" "<<nums[idx]<<endl;
        int idx1=b_search(nums,idx,h,key);
        int idx2=b_search(nums,l,idx-1,key);
        // cout<<idx1<<" "<<idx2<<endl;
        if(idx1!=-1) return idx1;
        else if(idx2!=-1) return idx2;
        else return -1;
        
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends