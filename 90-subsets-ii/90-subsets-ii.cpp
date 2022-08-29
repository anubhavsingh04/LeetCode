class Solution {
public:
    void solve(vector<int>&nums,vector<int>op,int idx,vector<vector<int>>&ans)
    {
        ans.push_back(op);
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            op.push_back(nums[i]);
            solve(nums,op,i+1,ans);
            op.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,op,0,ans);
        return ans;
    }
};


// class Solution {
// public:
//     void solve(vector<int>&nums,vector<int>op,int idx,set<vector<int>>&st)
//     {
//         if(idx==nums.size()){
//             sort(op.begin(),op.end());
//             st.insert(op);
//             return;
//         }
//         solve(nums,op,idx+1,st);
//         op.push_back(nums[idx]);
//         solve(nums,op,idx+1,st);
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         set<vector<int>>st;
//         vector<vector<int>>ans;
//         vector<int>op;
//         solve(nums,op,0,st);
//         for(auto i:st) ans.push_back(i);
//         return ans;
//     }
// };