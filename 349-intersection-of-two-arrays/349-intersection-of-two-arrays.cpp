// Insert all the elements of nums1 into map
// iterate through nums2 ans check is nums2[1] is found in map 
// means this is common element hence store this element in another map(m2) to avoid repetetions 
// iterate through all the elements of m2 and push back in the ans vector
// Finally return the ans vector

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