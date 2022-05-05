class MyStack {
    queue<int> q_;

   public:
    MyStack() {}

    void push(int x) { q_.push(x); }

    int pop() {
        for (int i = 0; i < q_.size() - 1; ++i) {
            q_.push(q_.front());
            q_.pop();
        }
        int v = q_.front();
        q_.pop();
        return v;
    }

    int top() {
        int v = pop();
        q_.push(v);
        return v;
    }

    bool empty() { return q_.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
