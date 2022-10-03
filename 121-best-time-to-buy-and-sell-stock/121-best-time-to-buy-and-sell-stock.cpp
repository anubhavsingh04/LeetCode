class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxprofit=0;
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,nums[i]);
            if(nums[i]>mini)
                maxprofit=max(maxprofit,nums[i]-mini);
        }
        return maxprofit;
    }
};