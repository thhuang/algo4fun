class MyCalendar {
    map<int, int> events;

   public:
    bool book(int start, int end) {
        auto it = events.upper_bound(start);
        if (it != events.begin() && prev(it)->second > start) return false;
        if (it != events.end() && it->first < end) return false;
        events[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
