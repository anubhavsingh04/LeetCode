class Solution {
public:
    bool is_kthbit_set(int i,int n)
    {
        if((1<<i)&n) return true;
        else return false;
    }
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(is_kthbit_set(i,n))
            {
                ans=ans|(1<<(31-i));
            }
        }
        return ans;
    }
};