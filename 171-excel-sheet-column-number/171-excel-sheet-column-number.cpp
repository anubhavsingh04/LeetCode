class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        unordered_map<char,int>m;
        char ch='A';
        for(int i=1;i<=26;i++)
        {
            m[ch]=i;
            ch++;
        }
        for(auto &i:s)
        {
            ans=ans*26+m[i];
        }
        return ans;
    }
};