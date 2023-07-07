class Solution {
public:
    int solve(string s,int k,char ch)
    {
        int left=0,right=0,ans=0,count=0;
        while(right<s.size())
        {
            if(s[right]==ch) count++; // this is invalid character count which is at max k allowed 
            if(left<s.size() && count>k){ 
                if(s[left]==ch) count--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,k,'T'),solve(answerKey,k,'F'));
                        // max False         max True
    }
};