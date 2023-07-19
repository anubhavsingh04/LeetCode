class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int cnt=0,left=0,right=1,n=nums.size();
        sort(nums.begin(),nums.end());
        // vector<vector<int>>ans;
        // ans.push_back(nums[0]);
        while(right<n)
        {
            if(nums[right][0]>=nums[left][1]) // not overlapped 
            {
                left=right;
            }
            else if(nums[right][1]>=nums[left][1])
            {
                cnt++;
            }
            else if(nums[right][1]<nums[left][1])
            {
                left=right;
                cnt++;
            }
            right++;
        }
        return cnt;
    }
};