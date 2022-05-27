class Solution {
public:
    int numberOfSteps(int num) {
        // msb of even no is 0 so n&1 will always be 0 for even 
        int cnt=0;
        while(num>0)
        {
            if(num&1) num-=1;
            else num>>=1;
               cnt++;
        }
        return cnt;
    }
};