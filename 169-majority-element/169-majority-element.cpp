// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         int f=n/2;
//         unordered_map<int,int>m;
//         for(auto &i:nums)
//         {
//             m[i]++;
//             if(m[i]>f)
//                 return i;
//         }
//         return -1;
//     }
// };


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         return nums[nums.size()/2];
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
        return nums[nums.size()/2];
    }
};