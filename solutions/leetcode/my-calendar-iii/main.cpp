class MyCalendarThree {
    vector<pair<int, int>> time_diff;

   public:
    int book(int start, int end) {
        auto s = upper_bound(
            time_diff.begin(), time_diff.end(), start,
            [](int t, pair<int, int>& v) -> bool { return t < v.first; });
        time_diff.insert(s, {start, 1});

        auto e = lower_bound(
            time_diff.begin(), time_diff.end(), end,
            [](pair<int, int>& v, int t) -> bool { return v.first < t; });
        time_diff.insert(e, {end, -1});

        int result = 0;
        for (int i = 0, s = 0; i < time_diff.size(); ++i) {
            result = max(result, s += time_diff[i].second);
        }

        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
