class Solution {
public:
    int passThePillow(int n, int t) {
        int round=t/(n-1);
        int reach=t%(n-1);
        if(round%2==0) {
            return reach+1;
        }
        else 
        {
            return n-reach;
        }
    }
};