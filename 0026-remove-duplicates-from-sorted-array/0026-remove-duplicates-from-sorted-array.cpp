class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0,idx=0;
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1]) 
            {
                cnt++;
                nums[idx]=nums[i];
                idx++;
            }
        }
        nums[idx]=nums[n-1]; // last element will always be there no matter whether duplicate of it is present or not 
        return cnt+1; // 1 extra element is inserted which is the last element
    }
};