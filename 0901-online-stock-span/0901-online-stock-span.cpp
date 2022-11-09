class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    stack<pair<int, int>> st;
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price)
        {
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};



// class StockSpanner {
// public:
//     StockSpanner() {
        
//     }
  
//     stack<pair<int, int>> st;
//     int next(int price) {
//         int res = 1;
//         while (!st.empty() && price>=st.top().first) {
//             res += st.top().second;
//             st.pop();
//         }
//         st.push({price, res});
//         return res;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */






// agr hame 1 1 1 2 1 4 6 as a vector return krna hota
// question will be like we will given 100,80,60,70,60,75,85 this as price and we have 
// to return 1,1,1,2,1,4,6 as ans 
// consecutive smaller or equal before it is equal to nearest greater to left
// left aaye to left se travese kro

// source GFG   Refrence Aditya verma 
// class Solution
// {
//     public:
//     //Function to calculate the span of stockâ€™s price for all n days.
//     vector <int> calculateSpan(int price[], int n)
//     {
//        stack<pair<int,int>>st;
//        vector<int>v;
//        for(int i=0;i<n;i++)
//        {
//            if(st.empty())
//            v.push_back(-1);
//            else if(st.top().first>price[i])
//            v.push_back(st.top().second);
//            else if(st.size()>0 && st.top().first<=price[i])
//            {
//                while(st.size()>0 && st.top().first<=price[i])
//                st.pop();
//                if(st.empty())
//                v.push_back(-1);
//                else 
//                v.push_back(st.top().second);
//            }
//            st.push({price[i],i});
//        }
//     //   ab hame vector me next greater to left ka index mil gya hai  
//     //   i-v[i] kr ne se ans aa jayega 
//        for(int i=0;i<v.size();i++)
//        v[i]=(i-v[i]);
//        return v;
//     }
// };