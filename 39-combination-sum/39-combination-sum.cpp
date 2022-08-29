// class Solution {
// public:
//     void solve(vector<int>& nums,vector<int>op,int idx,int target,vector<vector<int>>&ans)
//     {
//         if(target<0) return;
//         if(target==0)
//         {
//             ans.push_back(op);
//             return;
//         }
//         for(int i=idx;i<nums.size();i++)
//         {
//             op.push_back(nums[i]);
//             solve(nums,op,i,target-nums[i],ans);
//             op.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<int>op;
//         vector<vector<int>>ans;
//         solve(candidates,op,0,target,ans);
//         return ans;
//     }
// };



class Solution {
public:
    void solve(vector<int>& nums,vector<int>op,int idx,int sum,int target,vector<vector<int>>&ans)
    {
        if(sum>target) return;
        if(sum==target)
        {
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            sum+=nums[i];
            op.push_back(nums[i]);
            solve(nums,op,i,sum,target,ans);
            op.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>op;
        vector<vector<int>>ans;
        solve(candidates,op,0,0,target,ans);
        return ans;
    }
};


// class Solution {
// public:
//     void solve(vector<int>& nums,vector<int>op,int idx,int sum,int target,vector<vector<int>>&ans)
//     {
//         if(sum>target || idx>=nums.size()) return;
//         if(sum==target){
//             ans.push_back(op); 
//             return;
//         }
//         solve(nums,op,idx+1,sum,target,ans);
        
//         op.push_back(nums[idx]);
//         sum+=nums[idx];
//         solve(nums,op,idx,sum,target,ans);
//         sum-=nums[idx];
//         op.pop_back();
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int>op;
//         vector<vector<int>>ans;
//         solve(candidates,op,0,0,target,ans);
//         return ans;
//     }
// };