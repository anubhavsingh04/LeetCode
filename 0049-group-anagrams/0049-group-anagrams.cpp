class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>>mp;
        for(auto &str:strs)
        {
            map<char,int>freq_map;
            for(auto &ch:str)
            {
                freq_map[ch]++;
            }
            if(mp.find(freq_map)==mp.end())
            {
                vector<string>v;
                v.push_back(str);
                mp[freq_map]=v;
            }
            else 
            {
                mp[freq_map].push_back(str);
            }
        }
        vector<vector<string>>ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};