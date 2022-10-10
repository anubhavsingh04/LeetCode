class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        for(auto &i:arr)
        {
            m[i]++;
        }
        int cnt=0;
        for(auto &i:arr)
        {
            if(m[i]==1)
            {
                cnt++;
                if(cnt==k)
                {
                    return i;
                }
            }
        }
        return "";
    }
};