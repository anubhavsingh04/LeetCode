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
                    int val1=nums[x];
                    int val2=nums[y];
                    while(x<n && nums[x]==val1) x++;
                    while(y>=0 && nums[y]==val2) y--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto &i:st) ans.push_back(i);
        return ans;
    }
};