class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto &i:nums)
        {
            m[i]++;
        }
        for(auto &i:nums)
        {
            if(m[i]&1)
                return false;
        }
        return true;
    }
};