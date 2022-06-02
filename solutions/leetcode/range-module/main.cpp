class RangeModule {
    map<int, int> intervals;

   public:
    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin() && left <= prev(it)->second) {
            left = prev(it)->first;
            right = max(right, prev(it)->second);
        }

        while (it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it = intervals.erase(it);
        }

        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it == intervals.begin()) return false;
        return right <= prev(it)->second;
    }

    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin() && left <= prev(it)->second) {
            auto [prev_left, prev_right] = *prev(it);

            if (prev_left < left) {
                intervals[prev_left] = left;
            } else {
                intervals.erase(prev_left);
            }

            if (right < prev_right) {
                intervals[right] = prev_right;
                return;
            }
        }

        while (it != intervals.end() && it->first < right) {
            if (it->second <= right) {
                it = intervals.erase(it);
                continue;
            }
            intervals[right] = it->second;
            intervals.erase(it);
            break;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
