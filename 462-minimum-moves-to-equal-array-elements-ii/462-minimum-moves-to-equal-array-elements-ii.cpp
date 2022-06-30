
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        int median=nums[n/2];
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs(nums[i]-median);
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