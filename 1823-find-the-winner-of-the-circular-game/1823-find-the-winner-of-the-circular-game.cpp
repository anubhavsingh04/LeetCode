// Josephus problem 
// class Solution {
// public:
    
//     int findTheWinner(int n, int k) {
//         if(n==1) return 1;
//         else
//         {
//             int tmp=findTheWinner(n-1,k);
//             int ans=(tmp+k-1)%n+1;
//             return ans;
//         }
//     }
// };

class Solution {
public:
    void solve(int k,vector<int>v,int &ans,int index){
        if(v.size()==1){
            ans=v[0];
            return;
        }
        index=(index+k)%(v.size());
        v.erase(v.begin()+index);
        solve(k,v,ans,index);
        return;
    }
    
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        k--;
        int ans=-1;
        solve(k,v,ans,0);
        return ans;
    }
};