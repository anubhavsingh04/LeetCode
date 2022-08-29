// class Solution {
// public:
//     void solve(vector<int>& nums,vector<int>op,int idx,int target,vector<vector<int>>&ans)
//     {
//         if(idx==nums.size())
//         {
//             if(target==0){
//                 ans.push_back(op);
//             }
//             return;
//         }
//         if(nums[idx]<=target)
//         {
//             op.push_back(nums[idx]);
//             solve(nums,op,idx,target-nums[idx],ans);
//             op.pop_back(); 
//         }
//         solve(nums,op,idx+1,target,ans);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        if(sum>target || idx>=nums.size()) return;
        if(sum==target){
            ans.push_back(op); 
            return;
        }
        solve(nums,op,idx+1,sum,target,ans);
        
        op.push_back(nums[idx]);
        sum+=nums[idx];
        solve(nums,op,idx,sum,target,ans);
        sum-=nums[idx];
        op.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        vector<vector<int>>ans;
        solve(candidates,op,0,0,target,ans);
        return ans;
    }
};