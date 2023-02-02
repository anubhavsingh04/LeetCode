class Solution {
public:
    unordered_map<char,int>mp;
    bool cmp(string s1,string s2){
        int n=s1.size();
        int i=0;
        while(i<n && s1[i]==s2[i]){
            i++;
        }
        if(i==n||mp[s1[i]]<mp[s2[i]]) return true;
        return false;
        
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string>v;
        for(int i=0;i<words.size();i++)
        {
            v.push_back(words[i]);
        }
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i;
        }
        sort(v.begin(),v.end(),[&](string s1,string s2){
            int n=s1.size();
            int i=0;
            while(i<n && s1[i]==s2[i]){
                i++;
            }
            if(i==n||mp[s1[i]]<mp[s2[i]]) return true;
            return false;
        });
        for(int i=0;i<words.size();i++){
            if(words[i]!=v[i]) return false;
        }
        return true;
    }
};