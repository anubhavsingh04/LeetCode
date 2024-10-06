class Solution {
public:
    vector<string> getWords(string sentence)
    {
        vector<string>words;
        string word="";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' '){
                words.push_back(word);
                word="";
            }
            else{
                word+=sentence[i];
            }
        }
        words.push_back(word);
        return words;
    }
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> words1=getWords(s1);
        vector<string> words2=getWords(s2);
        if(words1.size()>words2.size()){
            swap(words1,words2);
        }
        int i=0,n1=words1.size();
        int j=n1-1;
        int right=words2.size()-1;
        // cout<<n1<<" "<<right+1;
        
        while(i<n1 && words1[i]==words2[i]){
            i++;
        }
        
        while(j>=0 && words1[j]==words2[right]){
            right--;
            j--;
        }
        return i>j;
    }
};