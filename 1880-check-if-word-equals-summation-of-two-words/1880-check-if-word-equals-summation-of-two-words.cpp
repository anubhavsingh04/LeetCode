class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a=0,b=0,target=0;
        for(int i=0;i<firstWord.size();i++){
            a=a*10+(firstWord[i]-'a');
        }
        
        for(int i=0;i<secondWord.size();i++){
            b=b*10+(secondWord[i]-'a');
        }
        
        for(int i=0;i<targetWord.size();i++){
            target=target*10+(targetWord[i]-'a');
        }
        
        return a+b==target;
    }
};