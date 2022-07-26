class Solution {
public:
    int sumofSqDigits(int n)
    {
        int sum=0;
        while(n>0)
        {
            int rem=n%10;
            sum+=(rem*rem);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n==1||n==7)
        return true;
        int tmp=n;
        while(true)
        {
            if(tmp==1)
            return true;
            if(tmp==89)
            return false;
            tmp=sumofSqDigits(tmp);
        }   
    }
};