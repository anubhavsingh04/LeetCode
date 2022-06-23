
// Brute force 
// class Solution {
// public:
//     int countPairs(vector<int>& nums, int k) {
//         int cnt=0;
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[i]==nums[j] && (i*j)%k==0)
//                     cnt++;
//             }
//         }
//         return cnt;
//     }
// };


// TC: O(n^2) Sc: O(m)


// Hashing Soln

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                for(auto &a:m[nums[i]])
                {
                    if((i*a)%k==0)
                        cnt++;
                }
            }
            m[nums[i]].push_back(i);
        }
        return cnt;
    }
};
