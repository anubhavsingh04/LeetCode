class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int left=0,right=0,sum=0,ans=1e9;
        int total=accumulate(nums.begin(),nums.end(),0); 
        int n=nums.size();
        int windowsz=n-k;
        if(k==n) return total;
        while(right<n)
        {
            sum+=nums[right++];
            if(right-left>=windowsz)
            {
                ans=min(ans,sum);
                sum-=nums[left++];
            }
        }
        
        return total-ans;
    }
};