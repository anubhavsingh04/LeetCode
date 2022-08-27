// class Solution {
// public:
//     vector<int> replaceElements(vector<int>& nums) {
//         int n=nums.size();
//         int maxi=nums[n-1];
//         vector<int>ans(n);
//         ans[n-1]=-1;
//         for(int i=n-2;i>=0;i--)
//         {
//             maxi=max(maxi,nums[i+1]);
//             ans[i]=maxi;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n=nums.size(),maxi=-1,curr;
        for(int i=n-1;i>=0;i--)
        {
            curr=nums[i];
            nums[i]=maxi;
            maxi=max(maxi,curr);
        }
        return nums;
    }
};