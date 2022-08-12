class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<int,int>m;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        int n=nums.size();
        // for(auto &i:nums)
        // {
        //     m[i]++;
        // }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long newtarget=(long long)target-nums[i]-nums[j];
                int x=j+1,y=n-1;
                while(x<y)
                {
                    int sum=nums[x]+nums[y];
                    if(sum==newtarget)
                    {
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