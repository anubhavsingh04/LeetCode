class Solution {
public:
    string sortSentence(string s) {
        // since no of words is from 1 to 9
        vector<string>pos(10,"");
        for(int i=0;i<s.size();i++)
        {
            int j=i; string tmp;
            while(!isdigit(s[j]))
            {
                tmp.push_back(s[j]);
                j++;
            }
            pos[s[j]-'0']=tmp;
            i=j+1;
        }
        string ans;
        for(int i=0;i<10;i++)
        {
            if(pos[i].length()>0)
            {
                ans+=pos[i];
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        return ans ;
    }
};