class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int small=INT_MAX,large=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=small)
            {
                small=nums[i];
            }
            else if(nums[i]>small && nums[i]<=large)
            {
                large=nums[i];
            }
            else { // if we came till here means we have a number which is greater than small as well as it is greater than large so the triplet is formed 
                return true;
            }
        }
        return false;
    }
};