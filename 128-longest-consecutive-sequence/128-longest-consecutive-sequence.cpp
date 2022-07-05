class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int longest=0,curr=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]==nums[i-1]+1)
            {
                curr++;
            }
            else {
                longest=max(longest,curr);
                curr=1;
            }
        }
        return nums.size()>0 ? max(longest,curr): 0;
    }
};