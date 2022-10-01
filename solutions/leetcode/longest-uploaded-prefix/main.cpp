class LUPrefix {
    priority_queue<int, vector<int>, greater<>> pq;
    int n = 0;

   public:
    LUPrefix(int n) {}

    void upload(int video) {
        pq.push(video);
        while (!pq.empty() && pq.top() == n + 1) {
            n = pq.top();
            pq.pop();
        }
    }

    int longest() { return n; }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
