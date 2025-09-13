class Solution {
public:
    int maxFreqSum(string s) {
        string vowels="aeiouAEIOU";
        unordered_map<char,int>mp;
        unordered_set<char>st(vowels.begin(),vowels.end());
        int vowelFreq=0,consonantFreq=0;
        for(auto &i:s){
            if(st.count(i)) 
            {
                mp[i]++;
                vowelFreq=max(vowelFreq,mp[i]);
            } else {
                mp[i]++;
                consonantFreq=max(consonantFreq,mp[i]);
            }
        }
        return vowelFreq+consonantFreq;
    }
};