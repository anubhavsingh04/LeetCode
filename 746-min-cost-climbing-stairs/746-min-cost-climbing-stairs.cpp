// Brute force gives tle 
// class Solution {
// public:
//     int solve(vector<int>& cost,int n)
//     {
//         if(n==0)
//             return cost[0];
//         if(n==1)
//             return cost[1];
//         return min(solve(cost,n-1),solve(cost,n-2))+cost[n];
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         return min(solve(cost,n-1),solve(cost,n-2));
//     }
// };



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp = cost;
        
        for (int i = 2; i < n; i++) {
            dp[i] += min(dp[i-2], dp[i-1]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};