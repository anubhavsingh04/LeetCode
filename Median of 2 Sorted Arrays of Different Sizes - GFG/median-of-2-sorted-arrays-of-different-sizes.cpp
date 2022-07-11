// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    // {
    //     // Your code goes here
    
    // }
    
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
    int m = nums2.size();
    if (n > m)
        return MedianOfArrays(nums2, nums1); // Swapping to make A smaller
 
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? nums1[leftAsize - 1]
                  : INT_MIN; // checking overflow of indices
        int leftB
            = (leftBsize > 0) ? nums2[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? nums1[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? nums2[leftBsize] : INT_MAX;
 
        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends