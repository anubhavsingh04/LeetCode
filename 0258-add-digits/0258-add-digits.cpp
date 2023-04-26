class Solution {
public:
    int rec(int num)
    {
        if(num<10) return num;
        int sum=0;
        while(num)
        {
            sum+=num%10;
            num/=10;
        }
        return rec(sum);
    }
    int addDigits(int num) {
        return rec(num);
    }
};