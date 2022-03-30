class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc=0,dec=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<= nums[i+1])
            inc++;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>= nums[i+1])
            dec++;
        }
        if(inc==nums.size()-1||dec==nums.size()-1)
        return true;
        return false;
    }
};