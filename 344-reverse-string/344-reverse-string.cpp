// // Using recursion (Induction,base case,hypothesis)
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         if(s.size()==0) return;     // base case
//         char ch=s[s.size()-1];
//         s.pop_back();
//         reverseString(s); 
// // above codn is hypothesis we will assume that it will give sorted string like=> l l e h o
//         s.insert(s.begin(),ch);  // induction
//     } 
// };

// Two pointer 

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int i = 0;
//         int j = s.size() - 1;
        
//         while(i <= j){
//             char temp = s[i];
//             s[i] = s[j];
//             s[j] = temp;
//             i++;
//             j--;
//         }
//     }
// };

// Stack

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(auto &i:s)
        {
            st.push(i);
        }
        s.clear();
        while(!st.empty())
        {
            s.push_back(st.top()); st.pop();
        }
    }
};