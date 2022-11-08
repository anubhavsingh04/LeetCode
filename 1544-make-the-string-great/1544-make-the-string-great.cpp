class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        int flag=0;
        while(true)
        {
            flag=0;
            for(int i=0;i<s.size()-1;i++)
            {
                if(abs(s[i]-s[i+1])==32)
                {
                    s.erase(i,2);
                    flag=1;
                    if(s.size()==0) {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==0) break;
        }
        return s;
    }
};