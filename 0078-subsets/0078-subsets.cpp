class Solution {
public:
    void solve(vector<int>&nums,vector<int>op,int idx,vector<vector<int>>&ans)
    {
        ans.push_back(op);
        for(int i=idx;i<nums.size();i++)
        {
            // if(i>idx && nums[i]==nums[i-1]) continue; 
            op.push_back(nums[i]);
            solve(nums,op,i+1,ans);
            op.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,op,0,ans);
        return ans;
    }
};

// array = [1,2,3,4]
// Subarray : [1,2],[1,2,3] - is continous and maintains relative order of elements
// Subsequence: [1,2,4] - is not continous but maintains relative order of elements
// Subset: [1,3,2] - is not continous and does not maintain relative order of elements