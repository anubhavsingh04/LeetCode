class Solution {
public:
    void rec(int idx,int sum,int target,vector<int>&nums,vector<int>tmp,vector<vector<int>>&ans)
    {
        if(sum==target){
            ans.push_back(tmp);
            return ;
        }
        if(sum>target) return;
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            sum+=nums[i];
            tmp.push_back(nums[i]);
            rec(i+1,sum,target,nums,tmp,ans);
            sum-=nums[i];
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<int>tmp;
        vector<vector<int>>ans;
        rec(0,0,target,c,tmp,ans);
        return ans;
    }
};