class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        map<int,int>mp1,mp2;
        for(auto &i:s) mp1[i]++;
        for(auto &i:t) mp2[i]++;
        for(auto i:mp2)
        {
            int x=i.first;
            int y=i.second;
            if(!mp1.count(x)) ans+=y;
            else if(y>mp1[x]) ans+=y-mp1[x];
        }
        return ans;
    }
};