class Solution {
public:
    int minCost(string colors, vector<int>& nums) {
        int time=0;
        int n=colors.size();
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                time+=min(nums[i],nums[i-1]);
                nums[i]=max(nums[i],nums[i-1]);
            }
        }
        return time;
    }
};