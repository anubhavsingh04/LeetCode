class Solution {
public:
    bool isOneBitCharacter(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1)
        {
            if(nums[i]==0) i++;
            else i+=2;
        }
        return i==nums.size()-1;
    }
};