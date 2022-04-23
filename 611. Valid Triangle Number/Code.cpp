class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--)
        {
            int left=0;
            int right=i-1;
            while(left<right)
            {
                if(nums[left]+nums[right]>nums[i])
                {
                        cnt+=right-left;
                        right--;
                }
                else 
                {
                    left++;
                } 
            }
        }
        
        return cnt;
    }
};

// Gives TLE
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         int cnt=0;
//         sort
//         for(int i=0;i<nums.size()-2;i++)
//         {
//             for(int j=i+1;j<nums.size()-1;j++)
//             {
//                 for(int k=j+1;k<nums.size();k++)
//                 {
//                     if(nums[i]+nums[j]>nums[k]&&nums[j]+nums[k]>nums[i]&&nums[k]+nums[i]>nums[j])
//                         cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
