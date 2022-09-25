class MyCircularQueue {
    int l = 0;
    int r = 0;
    int n;
    vector<int> data;

    bool full;

    int next(int i) { return (i + 1) % n; }

    int prev(int i) { return (i + n - 1) % n; }

   public:
    MyCircularQueue(int k) : n(k), full(k == 0), data(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        data[r] = value;
        r = next(r);
        full = l == r;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        l = next(l);
        full = false;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[l];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[prev(r)];
    }

    bool isEmpty() { return !full && r == l; }

    bool isFull() { return full; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
