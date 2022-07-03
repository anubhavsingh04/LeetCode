class Solution {
public:
    int countPoints(string rings) {
        int cnt=0;
        unordered_map<int,unordered_set<char>>m;
        for(int i=0;i<rings.size();i+=2)
        {
            char color=rings[i];
            int rod=rings[i+1];
            m[rod].insert(color);
        }
        for(auto &i:m)
        {
            if(m[i.first].size()>=3)
                cnt++;
        }
        return cnt;
    }
};