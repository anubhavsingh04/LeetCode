// 2*p=3*q
// extension*p=reflection*q

class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(!(p&1) && !(q&1))
        {
            p>>=1;
            q>>=1;
        }
        if(p&1 && (q&1)) return 1; // p odd and q odd 
        if(p&1 && !(q&1)) return 0; // p odd q even 
        else return 2; // p even q odd 
    }
};