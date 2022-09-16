class Solution {
public:
    int solve(int i,int k, vector<int>&nums,vector<int>& multipliers,vector<vector<int>>&dp)
    {
         if(k>=multipliers.size())return 0;
          int j=nums.size()-(k-i)-1;
         if(dp[k][i]!=INT_MIN)return (dp[k][i]);
          int ans=nums[i]*multipliers[k]+solve(i+1,k+1,nums,multipliers,dp);
               ans=max(ans,nums[j]*multipliers[k]+solve(i,k+1,nums,multipliers,dp));
          return dp[k][i]=ans;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n=nums.size(),m=multipliers.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        int i=0,j=n-1;
        return solve(i,0,nums,multipliers,dp);
        
    }
};