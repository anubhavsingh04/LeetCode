class Solution {
public:
    bool isequal(int n,map<int,int>m)
    {
        map<int,int>m2;
        while(n)
        {
            m2[n%10]++;
            n/=10;
        }
        return m2==m;
    }
    bool reorderedPowerOf2(int n) {
        map<int,int>digits;
        while(n)
        {
            digits[n%10]++;
            n/=10;
        }
        for(int i=0;i<32;i++)
        {
            if(isequal((1<<i),digits))
                return true;
        }
        return false;
    }
};