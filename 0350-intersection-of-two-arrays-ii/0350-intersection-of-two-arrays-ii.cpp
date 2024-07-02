class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp,mp2;
        for(auto i:nums1){
            mp[i]++;
        }
        for(auto i:nums2){
            mp2[i]++;
        }
        vector<int>ans;
        for(auto i:mp){
            if(mp2.count(i.first)){
                int mini=min(mp[i.first],mp2[i.first]);
                while(mini--) ans.push_back(i.first);
            }
        }
        return ans;
    }
};