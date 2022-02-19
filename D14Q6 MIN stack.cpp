class MinStack {
    stack<long long> st;
    long long mini = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long modVal = val;
        if(st.empty()){
            st.push(modVal);
            mini = modVal;
        }
        else{
            if(mini > modVal){
                st.push(2LL*modVal-mini); //modified value
                mini = modVal;
            }
            else{
                st.push(modVal);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long val = st.top();
        st.pop();
        if(mini > val){
            mini = 2*mini-val;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        else{
            long long ele = st.top();
            if(ele < mini){
                return mini;
            }
            else return ele;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
