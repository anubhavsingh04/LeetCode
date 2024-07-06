class Solution {
public:
    int passThePillow(int n, int time) {
        int rem=time/(n-1);
        int x=time%(n-1);
        if(rem%2==0){
            return x+1;
        }
        return n-x;
    }
};