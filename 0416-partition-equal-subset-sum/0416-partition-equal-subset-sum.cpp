// memoization
// class Solution {
// public:
//     bool rec(vector<int>&nums,int n,int sum,vector<vector<int>>&dp)
//     {
//         if(sum==0) return 1;
//         if(n==0) return false;
//         if(dp[n][sum]!=-1) return dp[n][sum];
//         if(nums[n-1]<=sum)
//         {
//             return dp[n][sum]=(rec(nums,n-1,sum-nums[n-1],dp)||rec(nums,n-1,sum,dp));
//         }
//         else {
//             return dp[n][sum]=rec(nums,n-1,sum,dp);
//         }
//     }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int sum=accumulate(nums.begin(),nums.end(),0);
//         if(sum&1) return false;
//         sum/=2;
//         vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
//         return rec(nums,n,sum,dp);
//     }
// };

// top down (tabulation)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        sum/=2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0 && j==0) dp[i][j]=1;
                else if(j==0) dp[i][j]=1;
                else if(i==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=(dp[i-1][j-nums[i-1]]||dp[i-1][j]);
                }
                else 
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};






// this is application of subset sum problem which states that whether any subset present in array such that sum of this subset is equal to target sum

// memoization for subset sum
// class Solution{   
// public:
//     bool rec(vector<int>&arr,int n,int sum,vector<vector<int>>&dp)
//     {
//         if(sum==0) return 1;
//         if(n==0) return 0; // ham yaha tabhi aye hain jab sum 0 nahi hai
//         if(dp[n][sum]!=-1) return dp[n][sum];
//         if(arr[n-1]<=sum)
//         {
//             return dp[n][sum]=rec(arr,n-1,sum-arr[n-1],dp)||rec(arr,n-1,sum,dp);
//         }
//         else 
//         return dp[n][sum]=rec(arr,n-1,sum,dp);
//     }
//     bool isSubsetSum(vector<int>arr, int sum){
//         int n=arr.size();
//         vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
//         return rec(arr,n,sum,dp);
//     }
// };


// Top down for  subset sum
// class Solution{   
// public:
//     bool isSubsetSum(vector<int>arr, int sum){
//         int n=arr.size();
//         int dp[n+1][sum+1];
//         for(int i=0;i<n+1;i++)
//         {
//             for(int j=0;j<sum+1;j++)
//             {
//                 if(i==0 && j==0) dp[i][j]=true;
//                 else if(i==0) // arr size is 0 we cant make any sum
//                 dp[i][j]=false;
//                 else if(j==0) // sum is 0 take empty subset 
//                 dp[i][j]=true;
//             }
//         }
//         for(int i=1;i<n+1;i++)
//         {
//             for(int j=1;j<sum+1;j++)
//             {
//                 if(arr[i-1]<=j) // take or not take 
//                 dp[i][j]=(dp[i-1][j-arr[i-1]]||dp[i-1][j]);
//                 else 
//                 dp[i][j]=dp[i-1][j];
//             }
//         }
//         return dp[n][sum];
//     }
// };