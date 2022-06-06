class Solution {
public:
    string destCity(vector<vector<string>>& v) {
        unordered_map<string,int>m;
        for(int i=0;i<v.size();i++)
        {
            m[v[i][0]]++;
        }
        for(int i=0;i<v.size();i++)
        {
            if(m[v[i][1]]<1)
                return v[i][1];
        }
        return "";
    }
};