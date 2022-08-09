

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int ans=0;
        const int MOD=1e9+7;
        map<int,long>dp;
        for(auto &i:arr)
        {
            dp[i]++;
        }
        for(auto &i:dp)
        {
            for(auto &j:dp)
            {
                if(i.first==j.first) break;
                if(i.first%j.first==0)
                {
                    if(dp.find(i.first/j.first)!=dp.end())
                    {
                        dp[i.first]=(dp[i.first]+dp[j.first]*dp[(i.first/j.first)])%MOD;
                    }
                }
            }
        }
        int sum=0;
        for(auto &i:dp)
        {
            sum=(sum+i.second)%MOD;
        }
        return sum%MOD;
    }
};