class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int cnt=0,size=chalk.size();
        long long sum=(accumulate(chalk.begin(),chalk.end(),0ll));
        k=k%sum;
        for(int i=0;i<chalk.size();i++)
        {
            k-=chalk[i];
            if(k<0)
                return i;
            cnt=(cnt+1)%size;
        }
        return cnt;
    }
};