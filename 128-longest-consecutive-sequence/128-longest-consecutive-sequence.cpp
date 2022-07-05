class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int len=1,curr=nums[i];
                while(s.find(curr+1)!=s.end())
                {
                    curr++;
                    len++;
                }
                longest=max(longest,len);
            }
        }
        return longest;
    }
};




// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int longest=0;
//         unordered_set<int>s(nums.begin(),nums.end());
        
//         for(auto &num: nums)
//         {
//             if(s.count(num-1))
//                 continue;
//             int j=1;
//             while(s.count(num+j))
//                 j++;
            
//             longest=max(longest,j);
//         }
//         return longest;
//     }
// };



// EASY
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int longest=0;
//         unordered_set<int>s(nums.begin(),nums.end());
        
//         for(auto &num: nums)
//         {
//             int curr=1;
//             for(int j=1;s.count(num-j);j++)
//             {
//                 s.erase(num-j);
//                 curr++;
//             }
//             for(int j=1;s.count(num+j);j++)
//             {
//                 s.erase(num+j);
//                 curr++;
//             }
//             longest=max(longest,curr);
//         }
//         return longest;
//     }
// };


// TC O(nlog(n))+O(n)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
        
//         int longest=0,curr=1;
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<nums.size();i++)
//         {
//             if(nums[i]==nums[i-1])
//                 continue;
//             else if(nums[i]==nums[i-1]+1)
//             {
//                 curr++;
//             }
//             else {
//                 longest=max(longest,curr);
//                 curr=1;
//             }
//         }
//         return nums.size()>0 ? max(longest,curr): 0;
//     }
// };