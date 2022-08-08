// Dutch national flag DNF sort
// Take low and mid as 0 and high as n-1
// traverse until mid<=high because each time nums[mid] is compared
// if nums[mid] is 0 then swap with nums[low] increase mid and low 
// if nums[mid] is 1 then just update the mid value as we want 1 in thre mid 
// lastly if nums[mid]==2 then swap with nums[high] and decrease high


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n=nums.size();
//         int low=0,mid=0,high=n-1;
//         while(mid<=high)
//         {
//             if(nums[mid]==0)
//             {
//                 swap(nums[low],nums[mid]);
//                 low++,mid++;
//             }
//             else if(nums[mid]==1)
//                 mid++;
//             else 
//             {
//                 swap(nums[mid],nums[high]);
//                 high--;
//             }
//         }
//     }
// };









class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            swap(nums[low],nums[mid]),mid++,low++;
            else if(nums[mid]==1) mid++;
            else
                swap(nums[mid],nums[high]),high--;
        }
    }
};