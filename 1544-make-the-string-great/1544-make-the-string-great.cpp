class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++)
        {
            
            if(not st.empty() and abs(s[i]-st.top())==32)
            {
                st.pop();
            }
            else 
            {
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};