class Solution {
public:
    void solve(vector<int>&nums,vector<int>op,int target,int idx,int sum,vector<vector<int>>&ans)
    {
        if(sum>target) return;
        if(sum==target){
            ans.push_back(op);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            
            op.push_back(nums[i]);
            sum+=nums[i];
            solve(nums,op,target,i+1,sum,ans);
            op.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>op;
        solve(candidates,op,target,0,0,ans);
        return ans;
    }
};



// class Solution {
// public:
//     void solve(vector<int>& nums, int target,int idx,vector<int>&v,vector<vector<int>>&ans)
//     {
//         if(target==0)
//         {
//             ans.push_back(v);
//             // return ;
//         }

//         for(int i=idx;i<nums.size();i++)
//         {
//             if(i!=idx && nums[i]==nums[i-1]) continue;
//             // if(nums[i]<=target)
//             // {
//             if(nums[i]>target) break;
//                 v.push_back(nums[i]);
//                 solve(nums,target-nums[i],i+1,v,ans);
//                 v.pop_back();
//             // }
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>>ans; 
//         vector<int>v;
//         solve(candidates,target,0,v,ans);
//         return ans;
//     }
// };



// (Bruteforce) Gives tle 
// class Solution {
// public:
//     void solve(vector<int>& nums, int target,set<vector<int>>&s,int idx,vector<int>&v)
//     {
//         if(idx==nums.size())
//         {
//             if(target==0)
//             {
//                 // ans.push_back(v);
//                 s.insert(v);
//             }
//             return ;
//         }
//         // pick element 
//         if(nums[idx]<=target)
//         {
//             v.push_back(nums[idx]);
//             solve(nums,target-nums[idx],s,idx+1,v);
//             v.pop_back();
//         }
//         // not pick
//         solve(nums,target,s,idx+1,v);

//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>>ans; set<vector<int>>s;
//         vector<int>v;
//         solve(candidates,target,s,0,v);
//         for(auto &i:s)
//         {
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };