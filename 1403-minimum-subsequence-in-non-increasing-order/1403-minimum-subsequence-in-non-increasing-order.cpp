class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        int sum=0;
        int s2=accumulate(nums.begin(),nums.end(),0)/2;
        for(int i=n-1;i>=0;i--)
        {
            if(sum>s2) break;
            sum+=nums[i];
            ans.push_back(nums[i]);
        }
        return ans;
    }
};