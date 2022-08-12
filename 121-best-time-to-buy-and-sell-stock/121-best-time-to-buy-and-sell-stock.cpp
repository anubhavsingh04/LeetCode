// Asked in google interview (imp)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
           mini=min(mini,prices[i]);
            if(prices[i]>mini)
            {
                maxprofit=max(maxprofit,prices[i]-mini);
            }
        }
        return maxprofit;
    }
};



// Naive approach TLE
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int maxprofit=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(prices[j]>prices[i])
//                 {
//                     maxprofit=max(maxprofit,prices[j]-prices[i]);
//                 }
//             }
//         }
//         return maxprofit;
//     }
// };