class HitCounter {
    int count = 0;
    deque<array<int, 2>> logs;  // {timestamp, count}

   public:
    void hit(int timestamp) {
        if (logs.empty() || logs.back()[0] != timestamp) {
            logs.push_back({timestamp, 1});
        } else {
            ++logs.back()[1];
        }
        ++count;
    }

    int getHits(int timestamp) {
        int t = timestamp - 300;
        while (!logs.empty() && logs.front()[0] <= t) {
            count -= logs.front()[1];
            logs.pop_front();
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
