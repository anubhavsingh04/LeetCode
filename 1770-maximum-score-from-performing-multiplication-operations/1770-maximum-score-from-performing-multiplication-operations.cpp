class Solution {
public:
    vector<vector<int>>dp;
    int findscore(int idx,int left,int right,vector<int>&nums,vector<int>&multipliers)
    {
        if(idx>=multipliers.size())
        {
            return 0;
        }
        if(dp[idx][left]!=INT_MIN) return dp[idx][left];
        int l= multipliers[idx]*nums[left] + findscore(idx+1,left+1,right,nums,multipliers);
        int r= multipliers[idx]*nums[right]+findscore(idx+1,left,right-1,nums,multipliers);
        return dp[idx][left]=max(l,r);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int idx=0;
        int left=0,right=nums.size()-1;
        int m=multipliers.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return findscore(idx,left,right,nums,multipliers);
    }
};