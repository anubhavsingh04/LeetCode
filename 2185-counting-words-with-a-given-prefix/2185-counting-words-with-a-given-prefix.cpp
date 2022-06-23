class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0,k=0;
        for(auto &word: words)
        {
            int n=pref.size();
            if(word.substr(0,n)==pref)
            cnt++;
        }
        return cnt;
    }
};