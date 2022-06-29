// using O(1) space 

// Pop
//  2 cases either st.top>=min_element (int this case pop() )
//  st.top()<min_element (int this case update the min val with 2*min_element-st.top())
// (because st.top() acting as corrupt val in this case and actual value is stored in min_element


// Push:
// if stack is empty then directly push into the stack and assign val to min_element else 
// 2 cases will arise either val>= min element or val< min element
// if val>=min_element then there will be no effect on min element just push in the stack
// but if val<min_element then push 2*val-min_element into the stack and assign val to then min element 

// top element 
//  2 cases either st.top>=min_element (in this case return  st.top())
//  but if st.top()<min_element 
// (in this case st.top() stores corrupt value and actual value is in min_element )




class MinStack {
public:
    stack<long>st;
     long min_element;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            min_element=val;
        }
        else if(val<min_element)
        {
            st.push(2ll*val-min_element);
            min_element=val;
        }
        else {
            st.push(val);
        } 
    }
    
    void pop() {
        if(st.empty()) return;
        
        if(st.top()<min_element)
        {
            min_element=(2ll*min_element-st.top());
            st.pop();
        }
        else {
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        if(st.top()<min_element)
            return min_element;
        else
            return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return min_element;
    }
};



// using extra space 

// class MinStack {
// public:
//     stack<int>s1;
//     stack<int>s2;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         s1.push(val);
//         if(s2.empty()||s1.top()<=s2.top())
//             s2.push(val);
//     }
    
//     void pop() {
//         if(s1.top()==s2.top())
//             s2.pop();
//         s1.pop();
//     }
    
//     int top() {
//         return s1.top();
//     }
    
//     int getMin() {
//         return s2.top();
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */