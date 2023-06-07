class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if((c&1)!=((a&1)|(b&1)))
            {
                if(((c&1)==0) && ((a&1)==1) && ((b&1)==1)){
                    ans+=2;
                }
                else {
                    ans+=1;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};