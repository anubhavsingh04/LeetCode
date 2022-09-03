class Solution {
public:
    void solve(int digit,int num,int cnt,int n,int k,vector<int>&ans)
    {
        if(cnt==n){
            ans.push_back(num);
            return;
        }
        
        for(int i=0;i<=9;i++)
        {
            if(abs(digit-i)==k)
            {
                solve(i,num*10+i,cnt+1,n,k,ans);
            }
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            solve(i,i,1,n,k,ans);
        }
        return ans;
    }
};