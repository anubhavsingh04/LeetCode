#include<bits/stdc++.h>
class Solution {
public:
    string vowelchange(string s){
        string st="aeiou";
        unordered_set<char>vowels(st.begin(),st.end());
        // transform(s.begin(),s.end(),s.begin(),::tolower);
        for(int i=0;i<s.size();i++){
            if(vowels.count(s[i])){
                s[i]='*';
            }
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string>ans;
        int n=wordlist.size(),m=queries.size();
        unordered_set<string>exactMatch;
        unordered_map<string,string>caseMismatch;
        unordered_map<string,string>vowelMismatch;
        for(auto &i:wordlist){
            string s1=i;
            transform(s1.begin(),s1.end(),s1.begin(),::tolower);
            string s2=vowelchange(s1);
            
            exactMatch.insert(i);
            if(!caseMismatch.count(s1)) caseMismatch[s1]=i;
            if(!vowelMismatch.count(s2)) vowelMismatch[s2]=i;
        }
        for(auto &i:queries){
            string s1=i;
            
            transform(s1.begin(),s1.end(),s1.begin(),::tolower);
            string s2=vowelchange(s1);
            if(exactMatch.count(i)) ans.push_back(i);
            else if(caseMismatch.count(s1)) ans.push_back(caseMismatch[s1]);
            else if(vowelMismatch.count(s2)) ans.push_back(vowelMismatch[s2]);
            else ans.push_back("");
        }
        return ans;
    }
};