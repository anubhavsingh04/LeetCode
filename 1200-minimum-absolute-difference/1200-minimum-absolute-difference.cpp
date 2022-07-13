class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        int diff=INT_MAX;
        for(int i=1;i<n;i++)
        {
            diff=min(diff,abs(nums[i]-nums[i-1]));
        }
        for(int i=1;i<n;i++)
        {
            if(abs(nums[i]-nums[i-1])==diff)
            {
                ans.push_back({nums[i-1],nums[i]});
            }
        }
        return ans;
    }
};