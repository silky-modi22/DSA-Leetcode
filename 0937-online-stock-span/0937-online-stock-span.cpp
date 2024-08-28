class StockSpanner {
public:
stack <pair<int,int>> st; 
int index = -1;
// whenever the constructoe call stack is clear and initialize with -1 index
    StockSpanner() {
        index = -1;
        st.empty();  
    }
    
    int next(int price) { 
        index = index+1;
        while(!st.empty() && st.top().first<= price)
        st.pop();
        int ans = index - (st.empty()?-1:st.top().second);
        st.push({price,index});
        return ans;
        
    }
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */