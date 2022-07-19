// insert 1 
// then iterate n times and just insert all the multiples i. num*2,num*3,num*5

class Solution {
public:
    int nthUglyNumber(int n) {
        set<long>s;
        s.insert(1);
        long num=1;
        while(n--)
        {
            num=*s.begin();
            s.erase(num);
            s.insert(num*2);
            s.insert(num*3);
            s.insert(num*5);
        }
        return num;
    }
};