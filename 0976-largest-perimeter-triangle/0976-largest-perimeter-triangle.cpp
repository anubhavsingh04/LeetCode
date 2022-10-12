class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int perimeter=0;
        int sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-3;i>=0;i--)
        {
            if(nums[i]+nums[i+1]>nums[i+2])
                perimeter=max(perimeter,nums[i]+nums[i+1]+nums[i+2]);
        }
        return perimeter;
    }
};