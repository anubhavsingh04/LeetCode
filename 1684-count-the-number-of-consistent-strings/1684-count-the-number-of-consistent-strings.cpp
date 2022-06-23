class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>m;
        int ans=0;
        for(auto &i:allowed)
            m[i]++;
        for(auto &i:words)
        {
            bool flag=true;
            for(auto &j:i)
            {
                if(m[j]==0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};