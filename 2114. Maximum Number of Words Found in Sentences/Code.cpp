#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        vector<int>v;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<sentences[i].size();j++)
            {
               if(sentences[i][j]==' ')
               cnt++;
            }
            maxi=max(maxi,cnt+1);
        }
        return maxi;
    }
};