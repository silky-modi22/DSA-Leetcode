class MyStack {
public:
 queue<int> q1;
 queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
       // Push the new element into q2
        q2.push(x);
        
        // Push all the elements of q1 into q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap the queues
        swap(q1, q2);    
    }
    
    int pop() {
      int ans = q1.front();
        q1.pop();
        return ans;
        
    }
    
    int top() {
        return q1.front();
        
    }
    
    bool empty() {
        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */