// consecutive smaller or equal before it is equal to nearest greater to left
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