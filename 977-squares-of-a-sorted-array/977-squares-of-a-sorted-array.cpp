// Just iterate from right and put max of abs(nums[right]), abs(nums[left])
// TC: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        int left=0,right=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(abs(nums[right])>abs(nums[left]))  
                ans[i]=nums[right]*nums[right--];
            else 
                ans[i]=nums[left]*nums[left++];
        }
        return ans;
    }
};

// TC: O(n) + o(nlog(n))=O(nlog(n))
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++)
//         {
//             nums[i]=nums[i]*nums[i];
//         }
//         sort(nums.begin(),nums.end());
//         return nums;
//     }
// };