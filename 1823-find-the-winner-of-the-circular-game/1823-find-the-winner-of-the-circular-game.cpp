class Solution {
public:
    int rec(int idx,int k,vector<int>&v)
    {
        if(v.size()<=1) return v[0];
        idx=(idx+k)%v.size();
        v.erase(v.begin()+idx);
        return rec(idx,k,v);
    }
    int findTheWinner(int n, int k) {
        k--;
        vector<int>v;
        for(int i=1;i<=n;i++)v.push_back(i);
        return rec(0,k,v);
    }
};

// Iterative 

// class Solution
// {
//     public:
//     int josephus(int n, int k)
//     {
//         int i=1,ans=0;
//         while(i<=n)
//         {
//             ans=(ans+k)%i;
//             i++;
//         }
//         return ans+1;
//     }
// };
