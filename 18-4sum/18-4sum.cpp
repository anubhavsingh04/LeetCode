class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                long long newtarget=(long long)target-nums[i]-nums[j];
                int x=i+1,y=j-1;
                while(x<y)
                {
                    long long sum=nums[x]+nums[y];
                    if(sum==newtarget){
                        st.insert({nums[i],nums[j],nums[x],nums[y]});
                        x++,y--;
                    }
                    else if(sum<newtarget) x++;
                    else y--;
                }
            }
        }
        for(auto &i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};