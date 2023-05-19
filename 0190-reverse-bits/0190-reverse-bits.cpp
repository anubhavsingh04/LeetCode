class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long ans=0;
        for(int i=0;i<32;i++)
        {
            long bit=n&1;
            ans=ans|(bit<<(31-i));
            n>>=1;
        }
        return ans;
    }
};