// using sorting 
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]==nums[i-1])
//                 return nums[i];
//         }
//         return -1;
//     }
// };




// using map
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>1)
                return nums[i];
        }
        return -1;
    }
};