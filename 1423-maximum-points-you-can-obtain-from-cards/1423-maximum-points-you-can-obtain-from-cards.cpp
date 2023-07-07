class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int left=0,right=0,sum=0,ans=1e9;
        int total=accumulate(nums.begin(),nums.end(),0); 
        int n=nums.size();
        int windowsz=n-k;
        while(right<windowsz)
        {
            sum+=nums[right++];
        }
        while(right<n)
        {
            ans=min(ans,sum);
            sum+=nums[right++];
            sum-=nums[left++];
        }
        ans=min(ans,sum);
        return total-ans;
    }
};