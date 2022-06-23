// agr kisi element ki freq odd hai then pair nahi ban skta
// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         unordered_map<int,int>m;
//         for(auto &i:nums)
//         {
//             m[i]++;
//         }
//         for(auto &i:nums)
//         {
//             if(m[i]&1)
//                 return false;
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();)
        {
            if(nums[i]!=nums[i-1])
                return false;
            i+=2;
        }
        return true;
    }
};