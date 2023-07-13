class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long newtarget=(long long)target-nums[i]-nums[j];
                int x=i+1,y=j-1;
                while(x<y)
                {
                    if(nums[x]+nums[y]<newtarget) x++;
                    else if(nums[x]+nums[y]>newtarget) y--;
                    else {
                        st.insert({nums[i],nums[j],nums[x],nums[y]});
                        int val1=nums[x];
                        int val2=nums[y];
                        while(x<n && nums[x]==val1)x++;
                        while(y>=0 && nums[y]==val2) y--;
                    }
                }
            }
        }
        for(auto &i:st) ans.push_back(i);
        return ans;
    }
};