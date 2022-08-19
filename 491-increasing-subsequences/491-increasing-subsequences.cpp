class Solution {
public:
    void solve(vector<int>&nums,vector<int>&v,set<vector<int>>&st,int idx,int n)
    {
        if(idx>nums.size()) return;
        if(v.size()>1) st.insert(v);
        for(int i=idx;i<n;i++)
        {
            if(v.empty()||nums[i]>=v.back())
            {
                v.push_back(nums[i]);
                solve(nums,v,st,i+1,n);
                v.pop_back();
            } 
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>v;
        solve(nums,v,st,0,nums.size());
        for(auto &i:st)
            ans.push_back(i);
        return ans;
    }
};



// class Solution {
// public:
//     void solve(int cnt,vector<int>&nums,vector<int>&v,set<vector<int>>&st)
//     {
//         if(cnt==nums.size()) {
//         if(v.size()>1)
//         {
//             st.insert(v);
//         }
//             return;
//         }
//         if(v.empty()||nums[cnt]>=v.back())
//         {
//             v.push_back(nums[cnt]);
//             solve(cnt+1,nums,v,st);
//             v.pop_back();
//         }
//         solve(cnt+1,nums,v,st);
//     }
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         set<vector<int>>st;
//         vector<vector<int>>ans;
//         vector<int>v;
//         solve(0,nums,v,st);
//         for(auto &i:st)
//             ans.push_back(i);
//         return ans;
//     }
// };