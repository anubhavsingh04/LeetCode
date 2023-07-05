class Solution {
public:
    int rec(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        long long ans=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            long long cost=nums[k]*nums[i-1]*nums[j+1]+rec(i,k-1,nums,dp)+rec(k+1,j,nums,dp);
            ans=max(ans,cost);
        }
        return dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) {
        int i=1,j=nums.size(),n=j;
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(i,j,nums,dp);
    }
};