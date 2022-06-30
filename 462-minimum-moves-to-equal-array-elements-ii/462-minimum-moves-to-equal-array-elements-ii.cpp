
// more optimised approach O(n)

// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         int n=nums.size();
        
//         sort(nums.begin(),nums.end());
//         int median=nums[n/2];
        
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             ans+=abs(nums[i]-median);
//         }
//         return ans;
//     }
// };



// O(n)+O(nlog(n))

// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         int n=nums.size();
        
//         sort(nums.begin(),nums.end());
//         int median=nums[n/2];
        
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             ans+=abs(nums[i]-median);
//         }
//         return ans;
//     }
// };



 // Now for any value x in the range the total steps needed to reach x for both the numbers is (x - nums[i]) + (nums[n-1-i] - x) = nums[n-1-i] - nums[i]



class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            ans+=nums[n-i-1]-nums[i];  
        }
        return ans;
    }
};







// Bruteforce gives tle 

// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         int n=nums.size();
//         long long ans=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//             long long moves=0;
//             for(int j=0;j<n;j++)
//             {
//                 moves+=abs(nums[i]-nums[j]);
//             }
//             ans=min(ans,moves);
//         }
//         return ans;
//     }
// };