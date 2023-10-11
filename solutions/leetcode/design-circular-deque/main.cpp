class MyCircularDeque {
    int n;
    vector<int> data;
    int l = 0, r = 0;

   public:
    MyCircularDeque(int k) : n(k + 1), data(k + 1, 0) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        l = (l - 1 + n) % n;
        data[l] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        data[r] = value;
        r = (r + 1) % n;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        l = (l + 1) % n;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        r = (r - 1 + n) % n;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return data[l];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return data[(r - 1 + n) % n];
    }

    bool isEmpty() { return l == r; }

    bool isFull() { return (r + 1) % n == l; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
