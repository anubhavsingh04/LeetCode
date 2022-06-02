class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int leftsum=0;
        for(int i=0;i<nums.size();i++)
        {
            totalsum-=nums[i];
            if(leftsum==totalsum)
                return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};