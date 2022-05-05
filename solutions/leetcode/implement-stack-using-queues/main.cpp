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

class MyStack {
    queue<void *> *head_ = nullptr;

   public:
    MyStack() {}

    void push(int x) {
        auto q = new queue<void *>();
        q->push((void *)x), q->push((void *)head_);
        head_ = q;
    }

    int pop() {
        int v = (char *)head_->front() - (char *)0;
        head_->pop();
        head_ = (queue<void *> *)head_->front();
        return v;
    }

    int top() { return (char *)head_->front() - (char *)0; }

    bool empty() { return head_ == nullptr; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
