class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push({s[i],1});
                continue;
            }
            else if(s[i]==st.top().first)
            {
                st.push({s[i],st.top().second+1});
                if(st.top().second==k)
                {
                    int x=k;
                    while(x--)
                    {
                        st.pop();    
                    }
                }
            }
            else if(s[i]!=st.top().first)
            {
                st.push({s[i],1});
            }
        }
        while(!st.empty())
        {
            char c=st.top().first;
            ans.push_back(c);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         stack<int>st;
//         for(int i=0;i<s.size();i++)
//         {
//             if(i==0||s[i]!=s[i-1])
//                 st.push(1);
//             else if(++st.top()==k)
//             {
//                 st.pop();
//                 s.erase(i-k+1,k);
//                 i=i-k;
//             }
//         }
//         return s;
//     }
// };