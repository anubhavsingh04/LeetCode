class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
       vector<int>ans;
       int sum=0;
       for(int i=0;i<nums.size();i++)
       {
           sum+=nums[i];
           ans.push_back(sum);
       }
       return ans;
    }
};

// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
//        vector<int>ans(nums.size());
//         ans[0]=nums[0];
//         for(int i=1;i<nums.size();i++)
//         {
//             ans[i]=ans[i-1]+nums[i];
//         }
//        return ans;
//     }
// };