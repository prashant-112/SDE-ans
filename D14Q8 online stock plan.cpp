class StockSpanner {
    stack<pair<int,int>> st;
    int ind;
public:
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind += 1;
        while(!st.empty() && st.top().second<=price)//finding previous greater element
                st.pop();
        if(st.empty()){
            st.push({ind,price});
            return ind+1;
        } 
        int prevind = st.top().first;
        st.push({ind,price});
        return ind-prevind;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
