class Solution {
public:
    int numberOfMatches(int n) {
        long long ans=0,mts=0,ta;
        while(n>2)
        {
            if(n%2==0)
            {
                mts+=n/2;
                ta=n/2;
                n=ta;
            }
            else
            {
                mts+=(n-1)/2;
                ta=(n-1)/2+1;
                n=ta;
            }
        }
        return n==1?0:mts+1;
    }
};