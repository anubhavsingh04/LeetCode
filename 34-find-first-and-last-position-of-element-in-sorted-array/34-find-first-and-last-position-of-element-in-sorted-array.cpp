// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int s=0,e=nums.size()-1;
//         vector<int>ans;
//         int ans1=-1,ans2=-1;
//         while(s<=e)
//         {
//             int mid=s+(e-s)/2;
//             if(nums[mid]==target)
//             {
//                 ans1 =mid;
//                 e=mid-1;
//             }
//             else if(target>nums[mid])
//                 s=mid+1;
//             else 
//                 e=mid-1;
//         }
//         ans.push_back(ans1);
//          int s1=0,e1=nums.size()-1;
//         while(s1<=e1)
//         {
//             int mid=s1+(e1-s1)/2;
//             if(nums[mid]==target)
//             {
//                 ans2 =mid;
//                 s1=mid+1;
//             }
//             else if (target>nums[mid])
//                 s1=mid+1;
//             else 
//                 e1=mid-1;
//         }
//         ans.push_back(ans2);
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {BinarySearch(nums, target, "first"), BinarySearch(nums, target, "last")};
    }
    
    int BinarySearch(vector<int> nums, int key, string find) {
        int s = 0, e = nums.size() - 1, mid;
        int ans = -1;

        while (s <= e) {
            mid = s+(e-s)/2;

            if (nums[mid] == key) {
                ans = mid; // first means finding the first occourence by e=mid-1
                                // lat means finding the last occourence by s=mid+1
                (find == "first") ? e = mid - 1 : s = mid + 1;
            }
            else if (nums[mid] > key) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};