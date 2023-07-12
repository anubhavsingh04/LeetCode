class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int i=0,j=0,ans=0,n=s.size();
        while(j<n)
        {
            if(!st.count(s[j])){
                st.insert(s[j]);
                ans=max(ans,j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};