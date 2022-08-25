class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                if(tokens[i]=="+") num1=num2+num1;
                if(tokens[i]=="-") num1=num2-num1;
                if(tokens[i]=="*") num1=num2*num1;
                if(tokens[i]=="/") num1=num2/num1;
                
                st.push(num1);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};