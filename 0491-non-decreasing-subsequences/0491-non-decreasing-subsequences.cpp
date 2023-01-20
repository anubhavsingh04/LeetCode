class Solution {
public:
    void rec(vector<int>&nums,int idx,set<vector<int>>&st,vector<int>v)
    {
        if(idx>nums.size()) return ;
        if(v.size()>1) st.insert(v);
        for(int i=idx;i<nums.size();i++)
        {
            if(v.empty()||nums[i]>=v.back())
            {
                v.push_back(nums[i]);
                rec(nums,i+1,st,v);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        vector<int>v;
        int idx=0;
        rec(nums,idx,st,v);
        for(auto &i:st) ans.push_back(i);
        return ans;
    }
};