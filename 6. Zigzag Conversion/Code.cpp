class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>str(numRows,"");
        int row=0,direction=1;
        if(numRows==1)
            return s;
        for(int i=0;i<s.size();i++)
        {
            str[row]+=s[i];
            if(row==0)
                direction=1;
            if(row==numRows-1)
                direction=-1;
            row+=direction;
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
                ans+=str[i];
        }
        return ans;
    }
};
