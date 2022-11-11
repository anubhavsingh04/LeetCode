class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1]) 
            {
                v.push_back(nums[i]);
            }
        }
        v.push_back(nums[n-1]);
        // for(auto i:v)
        // {
        //     cout<<i<<" ";
        // }
        for(int i=0;i<v.size();i++)
        {
            nums[i]=v[i];
        }
        return v.size();
    }
};