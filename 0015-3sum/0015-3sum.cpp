class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int target=-nums[i];
            int x=i+1,y=n-1;
            while(x<y)
            {
                if(nums[x]+nums[y]>target) y--;
                else if(nums[x]+nums[y]<target) x++;
                else {
                    st.insert({nums[i],nums[x],nums[y]});
                    x++;
                    y--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto &i:st) ans.push_back(i);
        return ans;
    }
};