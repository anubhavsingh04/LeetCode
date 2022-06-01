class Solution {
public:
    
    int findTheWinner(int n, int k) {
        if(n==1) return 1;
        else
        {
            int tmp=findTheWinner(n-1,k);
            int ans=(tmp+k-1)%n+1;
            return ans;
        }
    }
};