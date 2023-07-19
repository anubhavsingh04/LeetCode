class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int cnt=0,i=1,j=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        while(i<nums.size())
        {
            if(nums[i][0]<=ans[j][1]) {
                ans[j][1]=max(ans[j][1],nums[i][1]);
            }
            else {
                ans.push_back(nums[i]);
                j++;
            }
            i++;
        }
        return ans;
    }
};