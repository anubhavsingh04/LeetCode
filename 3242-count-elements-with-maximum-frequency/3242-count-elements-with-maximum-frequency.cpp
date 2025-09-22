class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=-1;
        for(auto i:nums){
            mp[i]++;
            maxi=max(maxi,mp[i]);
        }
        int ans=0;
        for(auto i:nums){
            if(mp[i]==maxi) ans++;
        }
        return ans;
    }
};