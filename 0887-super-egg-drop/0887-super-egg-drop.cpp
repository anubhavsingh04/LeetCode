// (if egg breaks at mid th floor then it will break from all the above floor so check for mid-1 floor only
// from a and b the one which is maximum will give min no of attempts in worst case 


class Solution {
public:
    vector<vector<int>>dp;
    int mcm(int egg,int floor)
    {
        if(floor==0||floor==1) return floor;
        if(egg==1) return floor;
        if(dp[egg][floor]!=-1) return dp[egg][floor];
        int ans=INT_MAX;
        int start=0,end=floor;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int a=mcm(egg-1,mid-1); // break 
            int b=mcm(egg,floor-mid); // not break
            int tmp=1+max(a,b); 
            if(a<b){
                start=mid+1;
            }
            else {
                end=mid-1;
            }
            
            ans=min(ans,tmp);
        }
        return dp[egg][floor]=ans;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,-1));
        return mcm(k,n);
    }
};