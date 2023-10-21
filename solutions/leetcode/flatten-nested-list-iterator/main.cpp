/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> data_;
    int i_ = 0;

    void process(const vector<NestedInteger>& vec) {
        for (const NestedInteger& ni : vec) {
            if (ni.isInteger())
                data_.push_back(ni.getInteger());
            else
                process(ni.getList());
        }
    }

   public:
    NestedIterator(vector<NestedInteger>& nestedList) { process(nestedList); }

    int next() { return data_[i_++]; }

    bool hasNext() { return i_ < data_.size(); }
};

class NestedIterator {
    vector<tuple<vector<NestedInteger>*, int>> active_;
    bool has_next_ = false;
    int val_;

    void getAllActive() {
        while (true) {
            auto [pv, i] = active_.back();
            if (pv->at(i).isInteger()) break;
            if (pv->at(i).getList().empty()) break;
            active_.push_back({&pv->at(i).getList(), 0});
        }
    }

   public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        active_.push_back({&nestedList, 0});
        getAllActive();
    }

    int next() {
        hasNext();
        has_next_ = false;
        return val_;
    }

    bool hasNext() {
        while (true) {
            if (has_next_) return has_next_;
            if (active_.empty()) return has_next_;

            auto [pv, i] = active_.back();
            active_.pop_back();

            if (pv->at(i).isInteger()) {
                val_ = pv->at(i).getInteger();
                has_next_ = true;
            }

            while (i + 1 >= pv->size()) {
                if (active_.empty()) return has_next_;

                tie(pv, i) = active_.back();
                active_.pop_back();
            }
            active_.push_back({pv, i + 1});

            getAllActive();
        }

        return has_next_;
    }
};

class NestedIterator {
    const int null = numeric_limits<int>::max();

    struct NestedIteratorList {
        const vector<NestedInteger>* data;
        int i = 0;

        const NestedInteger* current() const { return &data->at(i); }

        bool empty() const { return i == data->size(); }

        void forward() { ++i; }
    };

    stack<NestedIteratorList> stk;
    int nextValue = null;

    void forward() {
        if (nextValue != null) return;

        while (!stk.empty()) {
            if (stk.top().empty()) {
                stk.pop();
                continue;
            }

            auto it = stk.top().current();
            stk.top().forward();

            if (it->isInteger()) {
                nextValue = it->getInteger();
                return;
            }

            stk.push({&it->getList()});
        }
    }

   public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        stk.push({&nestedList});
    }

    int next() {
        forward();
        int result = nextValue;
        nextValue = null;
        return result;
    }

    bool hasNext() {
        forward();
        return nextValue != null;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
