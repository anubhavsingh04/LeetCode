class Solution {
public:
    
    int maxVowels(string s, int k) {
        set<char>vowels={'a','e','i','o','u'};
        int vc=0,l=0,ans=0,n=s.size(),r=0;
        
        auto check_vowel=[](char ch) {
            return (ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u');
        };
        
        while(r<n) {
            if(r<k-1) {
                if(check_vowel(s[r++])) vc++;
            }else {
                if(check_vowel(s[r++])) vc++;
                ans=max(ans,vc);
                if(check_vowel(s[l++])) vc--;
            }
            
        }
        return ans;
    }
};