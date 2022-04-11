class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum==target) return {i+1,j+1};
            else if(sum>target) j--;
            else i++;
        }
        return {}; // not found
    }
};


// class Solution {
// public:
// vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> sum;
//         for(int x = 0; x < numbers.size(); x++)
//         {
//             int low = 0, high = numbers.size()-1;
//             while(low <= high)
//             {
//                 int mid = low + (high - low)/2;
//                 if(numbers[mid] == target - numbers[x])
//                 {
//                     if(mid == x)
// 						low = mid + 1;  // moves low to next value in case the original value is the difference to be added
//                     else
//                     {
//                         sum = {x+1, mid+1};
//                         return sum;
//                     }
//                 }
//                 else if(numbers[mid] < target - numbers[x])
//                     low = mid + 1;
//                 else
//                     high = mid - 1;      
//             }
//         }
//        return sum;
//     }
// };