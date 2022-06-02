// class Solution {
// public:
//     int findMiddleIndex(vector<int>& nums) {
//         int totalsum=accumulate(nums.begin(),nums.end(),0);
//         int leftsum=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             totalsum-=nums[i];
//             if(leftsum==totalsum)
//                 return i;
//             leftsum+=nums[i];
//         }
//         return -1;
//     }
// };

// Prefix sum
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // int totalsum=accumulate(nums.begin(),nums.end(),0);
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        int totalsum=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            totalsum+=nums[i];
            prefix[i]=prefix[i-1]+nums[i];
        }
        if(totalsum-prefix[0]==0) return 0;
        else
        for(int i=1;i<nums.size();i++)
        {
            if(prefix[i-1]==(totalsum-prefix[i]))
            return i;
        }
        return -1;
    }
};