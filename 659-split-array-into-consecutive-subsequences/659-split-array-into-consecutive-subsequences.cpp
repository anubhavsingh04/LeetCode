class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        // int flag=0;
        for(auto &i:nums)
        {
            if(m[i]==0) continue;
            int curr=i;
            int freq=m[i];
            int cnt=0;
            while(m.find(curr)!=m.end() && m[curr]>=freq)
            {
                freq=max(freq,m[curr]);
                m[curr]--;
                curr++;
                cnt++;
            }
            if(cnt<3) return false;
        }
        return true;
    }
};