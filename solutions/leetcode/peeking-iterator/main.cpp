/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int curr_;
    bool has_next_;

   public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        has_next_ = Iterator::hasNext();
        curr_ = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return curr_; }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int prev = curr_;
        has_next_ = Iterator::hasNext();
        if (has_next_) curr_ = Iterator::next();
        return prev;
    }

    bool hasNext() const { return has_next_; }
};
