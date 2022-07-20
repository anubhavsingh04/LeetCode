class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>v(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(v[nums[i]]==1) return nums[i];
            v[nums[i]]=1;
        }
        return -1;
    }
};



// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         set<int>s;
//         for(auto &i:nums)
//         {
//             if(s.find(i)!=s.end()) return i;
//             s.insert(i);
//         }
//         return -1;
//     }
// };





// class Solution {
// public:
//     int solve(vector<int>nums)
//     {
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             if(nums[i]==nums[i+1])
//                 return nums[i];
//         }
//         return -1;
//     }
//     int findDuplicate(vector<int>& nums) {
//         return solve(nums);
//     }
// };