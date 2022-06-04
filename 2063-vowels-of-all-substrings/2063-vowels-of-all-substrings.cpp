class Solution {
public:
    long long countVowels(string s) {
        int sz=s.size();
        long long  ans=0,cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                long long l=sz-i; // right side ki no of substring starting with curr vowel
                ans +=((i*l)+l); // current vowelko chor ke no of substing formed by prev characters  
            }
        }
        return ans;
    }
};