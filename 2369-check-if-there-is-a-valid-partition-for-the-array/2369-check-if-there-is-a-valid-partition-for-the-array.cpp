// Recursion gives TLE
// class Solution {
// public:
//     int solve(int i,vector<int>&nums)
//     {
//         if(i==nums.size()) return 1;
//         int ans=0;
        
//         if(i+1<nums.size() && nums[i]==nums[i+1]){
//             ans=max(ans,solve(i+2,nums));
//         }
//         if(i+2<nums.size())
//         {
//             if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
//                 ans=max(ans,solve(i+3,nums));
//             else if(nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1)
//                 ans=max(ans,solve(i+3,nums));
//         }
//         return ans;
//     }
//     bool validPartition(vector<int>& nums) {
//         int ans=solve(0,nums);
//         return ans;
//     }
// };


// Memoize 
// since only i is changing make dp of size n+1
// check in each step if d[i]!=-1 return dp[i]
// else store the ans in dp vector then return 

class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==nums.size()) return 1;
        int ans=0;
        if(dp[i]!=-1) return dp[i];
        
        if(i+1<nums.size() && nums[i]==nums[i+1]) // two number pick 
        {
            ans=max(ans,solve(i+2,nums,dp));
        }
        if(i+2<nums.size()) // three number pick
        {
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
                dp[i]=ans=max(ans,solve(i+3,nums,dp));
            else if(nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1)
                dp[i]=ans=max(ans,solve(i+3,nums,dp));
        }
        return ans;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int ans=solve(0,nums,dp);
        return ans;
    }
};