class Solution {
public:
    void rec(int i,vector<int>&tmp,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(i>=nums.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[i]);
        rec(i+1,tmp,ans,nums);
        tmp.pop_back();
        rec(i+1,tmp,ans,nums);
        
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        int sum=0;
        rec(0,tmp,ans,nums);
        for(auto i:ans){
            vector<int>v=i;
            int xr=0;
            for(int i=0;i<v.size();i++){
                xr^=v[i];
            }
            sum+=xr;
        }
        return sum;
    }
};