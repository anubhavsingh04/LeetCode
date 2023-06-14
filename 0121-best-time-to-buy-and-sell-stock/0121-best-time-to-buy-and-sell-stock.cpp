class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0,n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,nums[i]);
            if(nums[i]>mini){
                ans=max(ans,nums[i]-mini);
            }
        }
        return ans;
    }
};