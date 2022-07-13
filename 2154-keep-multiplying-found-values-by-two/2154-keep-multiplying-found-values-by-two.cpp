class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>s(nums.begin(),nums.end());
        for(auto &i:s)
        {
            if(s.find(original)!=s.end())
                original*=2;
            else break;
        }
        return original;
    }
};