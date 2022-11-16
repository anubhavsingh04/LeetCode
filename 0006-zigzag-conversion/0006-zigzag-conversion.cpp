class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        vector<string>v(n,"");
        int row=0,dir=1;
        for(int i=0;i<s.size();i++)
        {
            v[row]+=s[i];
            if(row==0) dir=1;
            if(row==n-1) dir=-1;
            row+=dir;
        }
        string ans="";
        for(int i=0;i<v.size();i++)
        {
            ans+=v[i];
        }
        return ans;
    }
};