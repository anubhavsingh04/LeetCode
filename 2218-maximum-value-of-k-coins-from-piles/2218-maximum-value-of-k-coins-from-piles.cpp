// consider piles[0]={1,100,3} 
// if we are picking 1 coins then value is 1 
// if we are picking 2 coins then value is 101
// if we are picking 3 coins then value is 104
// so we need to take prefix sum of each pile 

// now secondly we can choose maxm of k coins since there is 0 based indexing 
// so we if we are at index x then we are picking x+1 coins so x+1<=k 

// recursive tree will be like we have k coins to choose and we have choosen x coins from piles[idx] 
//       (k,idx)
//      /       \
// (k,idx+1)  piles[idx][x]+(k-1,idx+1)

class Solution {
public:
    
    int rec(vector<vector<int>>&piles,int idx,int k,vector<vector<int>>&dp)
    {
        if(idx>=piles.size()) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int ans=0;
        ans=max(ans,rec(piles,idx+1,k,dp));
        
        for(int x=0;x<piles[idx].size();x++)
        {
            if(x+1<=k)
            {
                ans=max(ans,piles[idx][x]+rec(piles,idx+1,k-x-1,dp));
            }
            else break;
        }
        
        return dp[idx][k]=ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0;i<piles.size();i++)
        {
            for(int j=1;j<piles[i].size();j++)
            {
                piles[i][j]+=piles[i][j-1];
            }
        }
        vector<vector<int>>dp(piles.size()+1,vector<int>(k+1,-1));
        return rec(piles,0,k,dp);
    }
};