class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int>ans;
        unordered_map<int,unordered_set<int>>m;
        for(auto &i:nums1)
        {
            m[i].insert(1);
        }
        for(auto &i:nums2)
        {
            m[i].insert(2);
        }
        for(auto &i:nums3)
        {
            m[i].insert(3);
        }
        for(auto &i:m)
        {
            if(i.second.size()>=2)
                ans.push_back(i.first);
        }
        return ans;
    }
};