//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// apply binary search on distance and maximize it 
// kisi do cow ke bich ke distnace ko maximize krna hai 
// ham distance pe binary search laga hai means ham check krenge ki dis jitni distance rkh ke kisi bhi
// do cows ke bich me kya sare cows ko place kr sakte hain agar kar skte hain to distance ko badhane 
// ka try kro 
class Solution {
public:
    bool canplace(int dis,int k,vector<int>&nums)
    {
        int cows=1,prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-prev>=dis){
                prev=nums[i];
                cows++;
            }
        }
        return cows>=k;
    }
    int solve(int n, int k, vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int ans=-1;
        int start=1,end=nums[n-1]-nums[0];
        while(start<=end){
            int mid=(start+end)>>1;
            if(canplace(mid,k,nums)){
                ans=mid;
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends