class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)return false;
       long long x=abs(n);
        if(((x)&(x-1))==0)
        {
            int cnt=0;
            while(x)
            {
                x=x>>1;
                cnt++;
                
            }
            
            if(cnt%2)return true;
            return false;
        }
        return false;
    }
};