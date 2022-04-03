// Bruteforce gives tle
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         vector<int> result(T.size(),0);
//         for(int i=0;i<T.size();i++) {
//             int count = 0, flag = 0;
//             for(int j=i+1;j<T.size();j++) {
//                 count++;
//                 if(T[j] > T[i]) {flag = 1;break; }
//             }
//            result[i] = (flag==0)? 0 : count;
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>>st;
        vector<int>ans(T.size(),0);
        for(int i=0;i<T.size();i++)
        {
            while(!st.empty()&&T[i]>st.top().first)
            {
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({T[i],i});
        }
        return ans;
    }
};