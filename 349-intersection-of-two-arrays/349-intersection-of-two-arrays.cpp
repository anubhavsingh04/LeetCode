class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m,m2;
        vector<int>ans;
        for(auto &i:nums1)
            m[i]++;
        for(auto &i:nums2)
        {
            if(m.find(i)!=m.end())
                m2[i]++;
        }
        for(auto &i:m2)
            ans.push_back(i.first);
        return ans;
    }
};