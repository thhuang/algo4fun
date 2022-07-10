class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<>> pq;
    vector<bool> exists;

   public:
    SmallestInfiniteSet() : exists(10001, true) {
        for (int i = 1; i <= 1000; ++i) pq.push(i);
    }

    int popSmallest() {
        int v = pq.top();
        pq.pop();
        exists[v] = false;
        return v;
    }

    void addBack(int num) {
        if (exists[num]) return;
        exists[num] = true;
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
