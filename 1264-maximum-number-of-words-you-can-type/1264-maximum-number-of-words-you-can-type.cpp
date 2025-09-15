class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.size();
        unordered_set<char>broken(brokenLetters.begin(),brokenLetters.end());
        int ans=0,flag=0;
        for(int i=0;i<n;i++){
            if(broken.count(text[i])){
                flag=1;
            }
            if(text[i]==' '||i==n-1){
                if(flag==1) {
                    flag=0;
                }
                else ans++;
            }
        }
        return ans;
    }
};