class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
                return {m[target-nums[i]],i};
            m[nums[i]]=i;
        }
        return {};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int>ans;
//        for(int i=0;i<nums.size()-1;i++)
//        {
//            for(int j=i+1;j<nums.size();j++)
//                if(nums[i]+nums[j]==target)
//                {
//                     ans.push_back(i);
//                     ans.push_back(j);
//                }
//        }
//         return ans;
//     }
// };