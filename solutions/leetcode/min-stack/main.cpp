class MinStack {
    struct Entry {
        int val, min_val;
    };

    vector<Entry> data_;

   public:
    MinStack() {}

    void push(int val) {
        int min_val = val;
        if (!data_.empty()) min_val = min(min_val, data_.back().min_val);
        data_.push_back({val, min_val});
    }

    void pop() { data_.pop_back(); }

    int top() { return data_.back().val; }

    int getMin() { return data_.back().min_val; }
};

class MinStack {
    vector<int> mins;
    vector<int> vals;

   public:
    void push(int val) {
        vals.push_back(val);
        mins.push_back(mins.empty() ? val : min(mins.back(), val));
    }

    void pop() {
        mins.pop_back();
        vals.pop_back();
    }

    int top() { return vals.back(); }

    int getMin() { return mins.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
