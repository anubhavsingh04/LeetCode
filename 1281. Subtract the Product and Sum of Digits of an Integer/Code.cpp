class Solution {
public:
    int subtractProductAndSum(int n) {
        long long int pdt=1,sum=0;
        int temp=n;
        while(temp>0)
        {
            // int temp=n;
            int rem=temp%10;
            pdt*=rem;
            sum+=rem;
            temp=temp/10;
        }
        return (pdt-sum);
    }
};