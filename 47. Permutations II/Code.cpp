// class Solution {
// public:
//     vector<vector<int>>ans;
//     void solve(vector<int>nums,int idx)
//     {
//         if(nums.size()==idx)
//             ans.push_back(nums);
//         for(int i=idx;i<nums.size();i++)
//         {
//             if(i!=idx&&nums[i]==nums[idx])
//                 continue;
//             swap(nums[i],nums[idx]);
//             solve(nums,idx+1);
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         solve(nums,0);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
            ans.push_back(nums);
        return ans;
    }
};