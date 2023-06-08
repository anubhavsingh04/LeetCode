class MyQueue {
public:
    stack<int>st;
    stack<int>tmp;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }
        tmp.push(x);
        while(!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        int curr=st.top();
        st.pop();
        return curr;
    }
    
    int peek() {
       return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */