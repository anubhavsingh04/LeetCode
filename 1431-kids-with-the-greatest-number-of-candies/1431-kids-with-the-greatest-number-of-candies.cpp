class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool>ans(candies.size(),false);
        int maxi=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++)
        {
            ans[i]=(candies[i]+extra>=maxi?true:false);
        }
        return ans;
    }
};