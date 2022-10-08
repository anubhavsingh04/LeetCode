class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int x=i+1,y=n-1;
            while(x<y)
            {
                int sum=nums[i]+nums[x]+nums[y];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[x],nums[y]});
                    int val1=nums[x];
                    while(x<n && nums[x]==val1) x++;
                    int val2=nums[y];
                    while(y>=0 && nums[y]==val2) y--;
                }
                else if(sum<0) x++;
                else y--;
            }
        }
        return ans;
    }
};