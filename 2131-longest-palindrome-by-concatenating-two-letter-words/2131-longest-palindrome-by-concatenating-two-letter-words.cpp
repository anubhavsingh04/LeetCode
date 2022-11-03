class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int unpaired=0,ans=0;
        for(auto &w:words)
        {
            string rev=w;
            reverse(rev.begin(),rev.end());
            if(mp[rev]>0)
            {
                mp[rev]--;
                ans+=4;
            }
            else 
            {
                mp[w]++;
            }
        }
        for(auto &i:mp)
        {
            if(i.second==1 && i.first[0]==i.first[1])
            {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};