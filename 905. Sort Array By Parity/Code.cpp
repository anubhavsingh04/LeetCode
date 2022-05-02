class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>ans;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]%2==0){
                i++;
                continue;
            }
            if(nums[j]%2==1){
                j--;
                continue;
            }
            swap(nums[i],nums[j]);
            i++,j--;
        }
        return nums;
    }
};

// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         vector<int>ans;
//         int i=0,j=nums.size()-1;
//         while(i<j)
//         {
//             if(nums[i]%2==0){
//                 i++;
//                 continue;
//             }
//             if(nums[j]%2==1){
//                 j--;
//                 continue;
//             }
// 			if(nums[i]%2==1&&nums[j]%2==0)
// 			{
// 				swap(nums[i],nums[j]);
//             	i++,j--;
// 			} 
//         }
//         return nums;
//     }
// };