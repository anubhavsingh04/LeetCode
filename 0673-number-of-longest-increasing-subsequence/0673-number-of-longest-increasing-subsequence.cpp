class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxi=-1;
        vector<int>dp(n,1),ct(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]) {
                    dp[i]=1+dp[j];
                    ct[i]=ct[j];
                }
                else if(nums[j]<nums[i] && 1+dp[j]==dp[i]){
                    ct[i]+=ct[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                count+=ct[i];
            }
        }
        return count;
    }
};