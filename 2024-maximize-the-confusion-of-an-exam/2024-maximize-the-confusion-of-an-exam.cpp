class Solution {
public:
    
    int maxConsecutiveAnswers(string s, int k) {
        int ansT=0,ansF=0,countT=0,countF=0,n=s.size();
        int left=0,right=0;
        while(right<s.size())
        {
            if(s[right]=='F') countF++; // this is invalid character count which is at max k allowed 
            if(left<s.size() && countF>k){ 
                if(s[left]=='F') countF--;
                left++;
            }
            ansF=max(ansF,right-left+1);
            right++;
        }
        
        left=0,right=0;
        while(right<s.size())
        {
            if(s[right]=='T') countT++; // this is invalid character count which is at max k allowed 
            if(left<s.size() && countT>k){ 
                if(s[left]=='T') countT--;
                left++;
            }
            ansT=max(ansT,right-left+1);
            right++;
        }
        return max(ansT,ansF);
    }
};