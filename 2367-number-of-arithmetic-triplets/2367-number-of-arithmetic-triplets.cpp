// Brute force 
// we will check condition for k only if nums[j]-nums[i]==diff

// class Solution {
// public:
//     int arithmeticTriplets(vector<int>& nums, int diff) {
//         int ans=0;
//         for(int i=0;i<nums.size()-2;i++)
//         {
//             for(int j=i+1;j<nums.size()-1;j++)
//             {
//                 if(nums[j]-nums[i]==diff)
//                 for(int k=j+1;k<nums.size();k++)
//                 {
//                     if(nums[k]-nums[j]==diff)
//                         ans++;
//                 }
//             }
//         }
//         return ans ;
//     }
// };



// O(n) Using maps 
//nums[j] and nums[k] can be written as nums[j]=nums[i]+diff --(1)
// and nums[k]=nums[j]+diff 
// nums[k]=nums[i]+2*diff from equation (1)
// create a map to store element of array
// check two conditon if(nums[i]+diff) is in map and nums[i]+2*diff is in map

// class Solution {
// public:
//     int arithmeticTriplets(vector<int>& nums, int diff) {
//         int ans=0;
//         map<int,int>m;
//         for(int i=0;i<nums.size();i++)
//         {
//             m[nums[i]]++;
//         }
//         for(auto &i:nums)
//         {
//             if(m[i+diff] && m[i+2*diff])
//                 ans++;
//         }
//         return ans;
//     }
// };


// single pass if there is some number x for which x-diff and x-2*diff is present in map then there will always be a triplet let see how 
//  we can write the given equation as nums[j]=nums[k]-diff and nums[i]=nums[k]-2*diff
// so if we can somehow find nums[k]-diff and nums[k]-2*diff this means we have found nums[i] and nums[j] which is required triplet for some number nums[k]
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0;
        map<int,int>m;
        
        for(auto &i:nums)
        {
            if(i-diff>=0 && m[i-diff] && m[i-2*diff])
                ans++;
            m[i]++;
        }
        
        return ans;
    }
};



// O(n) Using sets 
// class Solution {
// public:
//     int arithmeticTriplets(vector<int>& nums, int diff) {
//         int ans=0;
//         set<int>s(nums.begin(),nums.end());
//         for(auto &i:nums)
//         {
//             if(s.find(i+diff)!=s.end() && s.find(i+2*diff)!=s.end())
//                 ans++;
//         }
//         return ans;
//     }
// };


