class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(auto &word:sentences)
        {
            int x=count(word.begin(),word.end(),' ');
            ans=max(ans,x+1);
        }
        return ans;
    }
};