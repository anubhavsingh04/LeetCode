class Solution {
public:
    void solve(int k,int &ans,int idx,vector<int>&v)
    {
        if(v.size()==1){
            ans=v[0];
            return;
        }
        idx=(idx+k)%v.size();
        v.erase(v.begin()+idx);
        solve(k,ans,idx,v);
    }
    int findTheWinner(int n, int k) {
        k--;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
             v[i]=i+1;
        }
        int idx=0;
        int ans=0;
        solve(k,ans,0,v);
        return ans;
    }
};