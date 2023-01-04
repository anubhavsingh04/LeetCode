class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto i:tasks) mp[i]++;
        int ans=0;
        for(auto &i:mp){
            if(i.second==1) return -1;
            ans+=(i.second%3==0?i.second/3:i.second/3+1);
        }
        return ans;
    }
};