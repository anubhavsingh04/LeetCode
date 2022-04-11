class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int diffr=nums[n-1]-nums[0];
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=1;i<n;i++)
        {
            maxi=max(nums[n-1]-k,nums[i-1]+k);
            mini=min(nums[0]+k,nums[i]-k);
            diffr=min(diffr,maxi-mini);
        }
        return diffr;
    }
};