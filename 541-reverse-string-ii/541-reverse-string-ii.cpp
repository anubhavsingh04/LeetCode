class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        while(i<s.size())
        {
            reverse(s.begin()+i,min(s.begin()+i+k,s.end()));
            i+=2*k;
        }
        return s;
    }
};