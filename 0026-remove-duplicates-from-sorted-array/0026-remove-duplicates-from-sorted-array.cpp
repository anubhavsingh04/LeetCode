class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i+1<n && nums[i]!=nums[i+1])
            {
                nums[idx++]=nums[i];
            }
        }
        nums[idx++]=nums[n-1];
        return idx;
    }
};