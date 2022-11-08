class Solution {
public:
    string makeGood(string s) {
        for(int i=s.size()-2;i>=0;i--){
            if(abs(s[i]-s[i+1])==32)s.erase(i,2);
        }
        return s;
    }
};