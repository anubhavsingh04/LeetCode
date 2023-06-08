class Solution {
public:
    int b_search(vector<int>&nums)
    {
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]<0)
            {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans==-1?0:nums.size()-ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            cout<<b_search(grid[i])<<' ';
            ans+=b_search(grid[i]);
        }
        return ans;
    }
};