class MyCalendar {
    map<int, int> intervals;

   public:
    bool book(int start, int end) {
        auto it = intervals.lower_bound(start);
        if (it != intervals.begin() && start < prev(it)->second) return false;
        if (it != intervals.end() && it->first < end) return false;
        intervals[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
