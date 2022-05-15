class CountIntervals {
    int count_ = 0;
    map<int, int> intervals_;

   public:
    void add(int left, int right) {
        auto it = intervals_.upper_bound(left);

        if (it != intervals_.begin() && left <= prev(it)->second) {
            auto prev_it = prev(it);

            left = prev_it->first;
            right = max(right, prev_it->second);

            count_ -= prev_it->second - prev_it->first + 1;
            intervals_.erase(prev_it);
        }

        while (it != intervals_.end() && it->first <= right) {
            right = max(right, it->second);

            count_ -= it->second - it->first + 1;
            it = intervals_.erase(it);
        }

        count_ += right - left + 1;
        intervals_[left] = right;
    }

    int count() { return count_; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
