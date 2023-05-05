class Solution {
public:
    
    int maxVowels(string s, int k) {
        vector<char>vowels={'a','e','i','o','u'};
        int vc=0,l=0,ans=0,n=s.size(),r=0;
        while(r<n) {
            if(r<k-1) {
                if(find(vowels.begin(),vowels.end(),s[r])!=vowels.end()) vc++;
            }else {
                if(find(vowels.begin(),vowels.end(),s[r])!=vowels.end()) vc++;
                ans=max(ans,vc);
                if(find(vowels.begin(),vowels.end(),s[l])!=vowels.end()) vc--;
                l++;
            }
            r++;
        }
        return ans;
    }
};