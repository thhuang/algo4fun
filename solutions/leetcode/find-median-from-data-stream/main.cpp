class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;

   public:
    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if (left.size() == right.size()) return;

        left.push(right.top());
        right.pop();
    }

    double findMedian() {
        if (left.size() > right.size()) return left.top();
        return 0.5 * (left.top() + right.top());
    }
};

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;

   public:
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        double result = left.top();
        if (left.size() == right.size()) (result += right.top()) /= 2;
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
