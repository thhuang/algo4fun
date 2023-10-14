
class MyStack {
    queue<void *> *head_ = nullptr;

   public:
    MyStack() {}

    ~MyStack() {
        while (!empty()) pop();
    }

    void push(int x) {
        auto p = new queue<void *>();
        p->push((void *)x);
        p->push((void *)head_);
        head_ = p;
    }

    int pop() {
        int v = top();
        head_->pop();
        auto p = head_;
        head_ = (queue<void *> *)head_->front();
        delete p;
        return v;
    }

    int top() { return (char *)head_->front() - (char *)0; }

    bool empty() { return head_ == nullptr; }
};

class MyStack {
    queue<int> q;
    int last;

   public:
    void push(int x) {
        q.push(x);
        last = x;
    }

    int pop() {
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(last = q.front());
            q.pop();
        }
        int result = q.front();
        q.pop();
        return result;
    }

    int top() { return last; }

    bool empty() { return q.empty(); }
};

class MyStack {
    queue<int> q;

   public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int v = q.front();
        q.pop();
        return v;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
