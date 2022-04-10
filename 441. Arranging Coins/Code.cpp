class Solution {
public:
    int arrangeCoins(int n) {
        int s=0,e=n;
        while(s<=e)
        {
            long long int mid =s+(e-s)/2;
            long long int sum=(mid*(mid+1)/2);
            if(sum==n)
                return mid;
            else if(sum>n)
                e=mid-1;
            else 
                s=mid+1;
        }
        return s-1;
    }
};

Brute force

class Solution {
public:
    int arrangeCoins(int n) {
        long long int sum=0,cnt=0;
        while(sum<=n)
        {
            sum+=++cnt;
            
        }
        return cnt-1;
    }
};