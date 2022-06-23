// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==target)
//                 ans.push_back(i);
//         }
//         return ans;
//     }
// };


// count kr lo kitne element target se chote hai 
// and count the freq of target element
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        int k=0;
        int small=0,freq_of_target=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]<target)
               small++;
            else if(nums[i]==target)
                freq_of_target++;
        }
        for(int i=small;i<small+freq_of_target;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};