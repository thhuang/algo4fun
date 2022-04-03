class MyQueue {
    stack<int> in_;
    stack<int> out_;

    void in_to_out() {
        while (!::empty(in_)) {
            out_.push(in_.top());
            in_.pop();
        }
    }

   public:
    MyQueue() {}

    void push(int x) { in_.push(x); }

    int pop() {
        int v = peek();
        out_.pop();
        return v;
    }

    int peek() {
        if (::empty(out_)) in_to_out();
        return out_.top();
    }

    bool empty() { return ::empty(in_) && ::empty(out_); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
