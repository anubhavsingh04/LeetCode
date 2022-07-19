class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
                str+=s[i];
            else 
            {
                v.push_back(str);
                str="";
            }
        }
        v.push_back(str);
        if(v.size()!=pattern.size()) return false;
        unordered_map<char,string>m;
        unordered_set<string>st;
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(pattern[i])!=m.end())
            {
                if(m[pattern[i]]!=v[i]) return false;
            }
            else 
            {
                // we came in else block means curr character is new character 
                //if the string correcponding to this character is already in set 
                // then there will be many to one mapping 
                // i.e. same string is matching to two different character 
                if(st.count(v[i])>0) return false;
                m[pattern[i]]=v[i];
                st.insert(v[i]);
            }
        }
        return true;
    }
};