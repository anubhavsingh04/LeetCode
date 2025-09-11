class Solution {
public:
    string sortVowels(string s) {
        string vowels="aeiouAEIOU";
        unordered_set<char>st(vowels.begin(),vowels.end());
        string tmp="";
        for(auto i:s){
            if(st.count(i)) tmp+=i;
        }
        sort(tmp.begin(),tmp.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                s[i]=tmp[j++];
            }
        }
        return s;
    }
};