class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz=nums.size();
        int i=0;
        while(i<sz)
        {
            if(nums[i]==val)
            {
                nums[i]=nums[sz-1];
                sz--;
            }
            else i++;
        }
        return sz;
    }
};