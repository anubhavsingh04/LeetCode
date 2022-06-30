// more optimised approach O(n)
// nth_element(nums.begin(),nums.begin()+n/2,num.end()) this function will place the median element at 
// its correct position 

// basically it rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list.
// means nth element ko uski sahi position pr rkh dega using quick select method 

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int median=nums[n/2];
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=abs(nums[i]-median);
        }
        return ans;
    }
};



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

// class Solution {
// public:
//     int minMoves2(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         int ans=0;
//         for(int i=0;i<n/2;i++)
//         {
//             ans+=nums[n-i-1]-nums[i];  
//         }
//         return ans;
//     }
// };







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