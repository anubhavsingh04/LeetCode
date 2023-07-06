class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=1e9,n=nums.size();
        int start=0,end=0,sum=0;
        while(end<n)
        {
            if(sum<target) {
                sum+=nums[end++];
            }
            while(sum>=target) {
                ans=min(ans,end-start);
                sum-=nums[start++];
            }
        }
        return ans==1e9?0:ans;
    }
};