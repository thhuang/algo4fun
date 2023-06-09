class RecentCounter {
    deque<int> ts;

   public:
    int ping(int t) {
        while (!ts.empty() && ts.front() + 3000 < t) ts.pop_front();
        ts.push_back(t);
        return ts.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
