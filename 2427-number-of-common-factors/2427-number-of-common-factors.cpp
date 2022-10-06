class Solution {
public:
    int commonFactors(int a, int b) {
        int ans=1;
        for(int i=2;i<=gcd(a,b);i++)
        {
            ans+=(a%i==0 && b%i==0)?1:0;
        }
        return ans;
    }
};