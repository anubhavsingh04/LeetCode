class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int cnt=0,i=1,j=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        while(i<nums.size())
        {
            if(nums[i][0]>=ans[j][1]) // not overlapped 
            {
                ans.push_back(nums[i]);
                j++;
            }
            else if(nums[i][1]>=ans[j][1])
            {
                cnt++;
            }
            else if(nums[i][1]<ans[j][1])
            {
                ans[j][1]=nums[i][1];
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};