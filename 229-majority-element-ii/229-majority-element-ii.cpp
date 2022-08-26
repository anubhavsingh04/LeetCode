class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        int n=nums.size();
        int f=n/3;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>f && count(ans.begin(),ans.end(),nums[i])==0)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};