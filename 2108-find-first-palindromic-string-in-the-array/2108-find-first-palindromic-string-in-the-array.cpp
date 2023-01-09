class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string tmp=words[i];
            reverse(tmp.begin(),tmp.end());
            if(tmp==words[i]) return words[i];
        }
        return "";
    }
};