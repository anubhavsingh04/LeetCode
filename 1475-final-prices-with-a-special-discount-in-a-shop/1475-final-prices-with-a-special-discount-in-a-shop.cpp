// next smaller to right 
// first find out the array for next smaller on the right 
// then subtract price[i]-v[i]

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         vector<int>v;
//         stack<int>st;
//         for(int i=prices.size()-1;i>=0;i--)
//         {
//             if(st.empty())
//                 v.push_back(-1);
//             else if(st.top()<prices[i])
//                 v.push_back(st.top());
//             else if(st.size()>0 && st.top()>=prices[i])
//             {
//                 while(st.size()>0 && st.top()>prices[i]) // yaha pe equal allowed hai 
//                     st.pop();
//                 if(st.empty())
//                     v.push_back(-1);
//                 else 
//                     v.push_back(st.top());
//             }
//             st.push(prices[i]);
//         }
//         reverse(v.begin(),v.end());
//         for(int i=0;i<prices.size();i++)
//         {
//             if(v[i]!=-1)
//                 prices[i]-=v[i];
//         }
//         return prices;
//     }
// };


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>v(n);
        stack<int>st;
        // v[n-1]=prices[n-1];
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()>prices[i])
            st.pop();
            if(st.empty())
                v[i]=prices[i];
            else 
                v[i]=prices[i]-st.top();
            st.push(prices[i]);
        }
        return v;
    }
};




// next smaller to left

// stack<int>st;
// vector<int>v;
// for(int i=0;i<nums.size();i++)
// {
//     if(st.empty())
//     {
//         v.push_back(-1);
//     }
//     else if(st.top()<nums[i])
//         v.push_back(st.top());
//     else if(!st.empty() && st.top()>=nums[i])
//     {
//         while(!st.empty()&&st.top()>=nums[i])
//             st.pop();
//         if(st.empty())
//             v.push_back(-1);
//         else 
//             v.push_back(st.top());
//     }
//     st.push(nums[i]);
// }