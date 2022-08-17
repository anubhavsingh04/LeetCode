class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
                         "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
                         "-.--","--.."};
        set<string>st;
        for(auto &i: words)
        {
            string curr="";
            for(auto &j:i)
            {
                curr+=v[j-'a'];
            }
            st.insert(curr);
        }
        return st.size();
    }
};