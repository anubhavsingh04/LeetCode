class Solution {
public:
    bool judgeSquareSum(int c) {
        long int s=0,e=sqrt(c);
        while(s<=e)
        {
            long  int current=s*s+e*e;
            if(current==c)
                return true;
            else if(current<c)
                s++;
            else 
                e--;
        }
        return false ;
    }
};