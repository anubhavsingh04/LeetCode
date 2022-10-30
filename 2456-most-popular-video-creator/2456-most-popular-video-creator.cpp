class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& view) {
        unordered_map<string,pair<long long,pair<long long,string>>>mp;// creator -> popularity -> view,id
        long long maxi=0;
        vector<vector<string>>ans;
        for(int i=0;i<c.size();i++) {
            if(mp.find(c[i])!=mp.end()) {
                mp[c[i]].first+=view[i];
                if(view[i]>mp[c[i]].second.first) {
                    mp[c[i]].second.first=view[i];
                    mp[c[i]].second.second=id[i];
                }else if(view[i]==mp[c[i]].second.first) {
                    if(id[i]<mp[c[i]].second.second) {
                        mp[c[i]].second.second=id[i];
                    }
                }
            }else {
                mp[c[i]]={view[i],{view[i],id[i]}};
            }
            maxi=max(maxi,mp[c[i]].first);
        }
        for(auto [i,j]: mp) {
            if(j.first==maxi) {
                ans.push_back({i,j.second.second});
            }
        }
        return ans;
    }
};