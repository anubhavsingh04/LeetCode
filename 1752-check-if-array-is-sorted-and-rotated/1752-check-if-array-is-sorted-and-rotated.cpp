// if the array is sorted but not rotated then nums[n-1]>nums[0]
// if the array is rotated then at 1 index prev element will be greater than next element 5>1
// i.e. nums[i-1]>nums[i]

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0,n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i]) cnt++;
        }
        if(nums[n-1]>nums[0]) cnt++;
        
        return cnt<=1;
    }
};

