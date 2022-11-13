class Solution {
public:
    string reverseWords(string s) {
        string tmp="";
        stack<string>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ') continue;
            
            while(i<s.size() && s[i]!=' ')
            {
                tmp+=s[i];
                i++;
            }
            st.push(tmp);
            st.push(" ");
            tmp="";
        }
        st.pop();
        s="";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        return s;
    }
};