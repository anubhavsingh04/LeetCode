class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        int n=min(word1.size(),word2.size());
        int k=max(word1.size(),word2.size());
        int i=0;
        string ans;
        while(i<n)
        {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }
        if(n2>n1)
        ans.append(word2,i,k);
        else 
        ans.append(word1,i,k);
           return ans;
    }
     
};
