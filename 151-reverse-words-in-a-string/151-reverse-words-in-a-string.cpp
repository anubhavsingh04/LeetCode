class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++)
        {
            string ans="";
            if(s[i]==' ')
                continue;
           while(i<s.size()&&s[i]!=' ')
           {
               ans+=s[i]; i++;
           } 
            st.push(ans);
            st.push(" ");
        }
        st.pop();
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};