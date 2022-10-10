class MaxStack {
    struct CMP {
        bool operator()(list<pair<int, int>>::iterator a,
                        list<pair<int, int>>::iterator b) const {
            if (a->first != b->first) return a->first > b->first;
            return a->second > b->second;
        }
    };

    int i = 0;
    list<pair<int, int>> nums;
    set<list<pair<int, int>>::iterator, CMP> mx;

   public:
    void push(int x) {
        nums.push_back({x, i++});
        mx.insert(prev(nums.end()));
    }

    int pop() {
        int v = nums.back().first;
        mx.erase(prev(nums.end()));
        nums.pop_back();
        return v;
    }

    int top() { return nums.back().first; }

    int peekMax() { return (*mx.begin())->first; }

    int popMax() {
        int v = (*mx.begin())->first;
        nums.erase(*mx.begin());
        mx.erase(mx.begin());
        return v;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
