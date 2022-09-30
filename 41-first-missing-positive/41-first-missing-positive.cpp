// Put each element at its right position like 5 will be at positon 4 
// if nums[i]==5 then it should be at position nums[nums[i]-1]
// TC: O(n) SC: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1],nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};