class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> ip,op;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        ip.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int x=op.top();
        op.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(op.empty()){
            while(ip.size()){
                op.push(ip.top()),ip.pop();
            }
        }
        return op.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return op.empty()&&ip.empty();
    }
};