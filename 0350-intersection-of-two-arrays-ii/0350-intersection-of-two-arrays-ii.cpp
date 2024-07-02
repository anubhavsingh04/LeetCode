class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto i:nums1){
            mp[i]++;
        }
        vector<int>ans;
        for(auto i:nums2){
            if(mp[i]>0) {
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;
    }
};