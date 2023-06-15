class Solution {
public:
    int rec(int prev,int curr,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(curr>=nums.size()) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];
        int pick=0,notpick;
        if(prev==-1||nums[curr]>nums[prev]) {
            pick=1+rec(curr,curr+1,nums,dp);
        }
        notpick= rec(prev,curr+1,nums,dp);
        
        return dp[prev+1][curr]=max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(-1,0,nums,dp);
    }
};