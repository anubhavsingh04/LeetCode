// we can not check neighbour directly for any index because if we change that index i according 
// to the neighbour i+1 then may be error because index i+1 will further depend on index i+2
// so two times traversal will be required 

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
          vector<int>ans(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1] && ans[i]<=ans[i-1])
                ans[i]=ans[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1] && ans[i]<=ans[i+1])
                ans[i]=ans[i+1]+1;
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};