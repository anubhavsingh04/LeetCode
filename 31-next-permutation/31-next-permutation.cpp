// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int idx=-1;
//         for(int i=nums.size()-1;i>0;i--)
//         {
//             if(nums[i]>nums[i-1])
//             {
//                 idx=i-1;
//                 break;
//             }
//         }
//         if(idx<0)
//         {
//             reverse(nums.begin(),nums.end());
//             return;
//         }
//         for(int i=nums.size()-1;i>=0;i--)
//         {
//             if(nums[i]>nums[idx])
//             {
//                 swap(nums[i],nums[idx]);
//                 reverse(nums.begin()+idx+1,nums.end());
//                 break;
//             }
//         }
//     }
// };

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(),nums.end());
//     }
// };


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                index=i-1;
                break;
            }
        }
        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[index])
            {
                swap(nums[i],nums[index]);
                reverse(nums.begin()+index+1,nums.end());
                return;
            }
        }
    }
};