class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        vector<pair<int,char>>v;
        for(int i=0;i<indices.size();i++)
        {
            v.push_back(make_pair(indices[i],s[i]));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<indices.size();i++)
        ans.push_back(v[i].second);
        return ans;
    }
};