class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n=words.size();
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            map<char,char>m1,m2;
            int mapped=1;
            string curr=words[i];
            int m=curr.size();
            for(int j=0;j<m;j++)
            {
                // checking mapping from curr word to pattern 
                if(m1.find(curr[j])==m1.end()) // if not found in map
                {
                    m1.insert({curr[j],pattern[j]});
                }
                else 
                {
                    if(m1[curr[j]]!=pattern[j])
                    {
                        mapped=0;
                        break;
                    }
                }
                // similarly checking for pattern to word (bijection condition i.e. both ways)
                if(m2.find(pattern[j])==m2.end()) // if not found in map
                {
                    m2.insert({pattern[j],curr[j]});
                }
                else 
                {
                    if(m2[pattern[j]]!=curr[j])
                    {
                        mapped=0;
                        break;
                    }
                }
            }
            if(mapped) ans.push_back(curr);
        }
        return ans;
    }
};