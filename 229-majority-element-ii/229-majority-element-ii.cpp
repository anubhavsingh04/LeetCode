class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int f=n/3;
        vector<int>ans;
        unordered_set<int>s;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>f)
                s.insert(nums[i]);
        }
        for(auto &i:s)
            ans.push_back(i);
        return ans;
    }
};