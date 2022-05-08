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

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
