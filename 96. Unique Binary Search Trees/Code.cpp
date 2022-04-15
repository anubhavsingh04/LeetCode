class Solution {
public:
    long long BinomialCoffecient( int n,int k)
    {
        if(k>n-k)
            k=n-k;
        long long result=1;
        for(int i=0;i<k;i++)
        {
            result*=(n-i);
            result/=(i+1);
        }
        return result;
    }
    int numTrees(int n) {
        return BinomialCoffecient(2*n,n)/(n+1);
    }
};