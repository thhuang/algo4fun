class CountIntervals {
    int count_ = 0;
    map<int, int> intervals_;

   public:
    void add(int left, int right) {
        if (intervals_[left]) {
            count_ -= intervals_[left] - left + 1;
        }

        intervals_[left] = max(intervals_[left], right);
        count_ += right - left + 1;

        auto it = intervals_.find(left);
        if (it != intervals_.begin()) {
            auto prev = it;
            --prev;
            if (prev->second >= it->first) {
                count_ -= prev->second - prev->first + 1;
                count_ -= it->second - it->first + 1;

                prev->second = max(prev->second, it->second);

                count_ += prev->second - prev->first + 1;

                intervals_.erase(it);
                it = prev;
            }
        }
        ++it;

        for (; it != intervals_.end(); ++it) {
            auto prev = it;
            --prev;

            if (prev->second < it->first) break;

            count_ -= prev->second - prev->first + 1;
            count_ -= it->second - it->first + 1;

            prev->second = max(prev->second, it->second);

            count_ += prev->second - prev->first + 1;

            it = --intervals_.erase(it);
        }
    }

    int count() { return count_; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
