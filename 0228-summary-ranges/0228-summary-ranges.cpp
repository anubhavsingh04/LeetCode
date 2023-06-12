class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;
        string s="";
        for(int i=0;i<n;i++)
        {
            int j=i;
            while(j+1<n && nums[j+1]==nums[j]+1) {
                j++;
            }
            if(j>i){
                s+=to_string(nums[i])+"->"+to_string(nums[j]);
            }
            else {
                s+=to_string(nums[i]);
            }
            ans.push_back(s);
            s="";
            i=j;
        }
        return ans;
    }
};