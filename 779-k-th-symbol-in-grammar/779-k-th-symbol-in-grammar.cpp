// Recursion (basically hame 0 ka 0 1 and 1 ka 1 0 banana hai)
//              0 
//              0 1 |
//              0 1 | 1 0 
// if we carefully observe first half of each next iteration is same as previous
// and second half is complemented corresponding to first half of prev   
                  
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1&&k==1) return 0;
        int mid=(1<<(n-1))>>1;
        if(k<=mid)
            return kthGrammar(n-1,k);
        else 
            return !(kthGrammar(n-1,k-mid));
    }
};