class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int,int>mp;
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]]=i;
        }
        for(int i=1;i<words.size();i++)
        {
            string w1=words[i-1];
            string w2=words[i];
            int idx1=0,idx2=0;
            while(idx1<w1.size() && idx2<w2.size() && w1[idx1]==w2[idx2])
            {
                idx1++;
                idx2++;
            }
            if(idx1<w1.size() && idx2==w2.size()) return false;
            if(idx1<w1.size() && idx2<w2.size() ) 
            {
                if(mp[w1[idx1]]>mp[w2[idx2]])return false;
            }
        }
        return true;
    }
};