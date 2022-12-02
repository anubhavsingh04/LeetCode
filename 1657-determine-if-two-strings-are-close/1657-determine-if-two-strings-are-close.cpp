class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        if(n!=m) return false;
        map<char,int>mp1,mp2,freq1,freq2;
        set<char>st1,st2;
        for(int i=0;i<n;i++)
        {
            mp1[word1[i]]++;
            st1.insert(word1[i]);
            mp2[word2[i]]++;
            st2.insert(word2[i]);
        }
        for(auto i:mp1) freq1[i.second]++;
        for(auto i:mp2) freq2[i.second]++;
        return freq1==freq2 && st1==st2;
    }
};