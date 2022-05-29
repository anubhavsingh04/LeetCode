class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0,cnt=0;
        for(auto &i:s)
        {
            if(i=='L') cnt++;
            if(i=='R') cnt--;
            if(cnt==0) ans++;
        }
        return ans;
    }
};