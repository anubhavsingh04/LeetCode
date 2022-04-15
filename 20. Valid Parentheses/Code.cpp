class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,int>m={ {'(',-1},{')',1},{'{',-2},{'}',2},{'[',-3},{']',3} };
        for(char ch: s)
        {
            if(m[ch]<0)
            {
                st.push(ch);
            }
            else 
            {
                if(st.empty())
                    return false ;
                else 
                {
                    char c=st.top();
                    if(m[ch]+m[c]!=0)
                        return false ;
                    else 
                        st.pop();
                }
            }
        }
        return st.empty();
    }
};