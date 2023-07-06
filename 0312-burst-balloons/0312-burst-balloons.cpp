class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int i=1,j=nums.size(),n=j;
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j) continue;
                long long ans=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    long long cost=nums[k]*nums[i-1]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    ans=max(ans,cost);
                }
                dp[i][j]= ans;
            }
        }
        return dp[1][n];
    }
};