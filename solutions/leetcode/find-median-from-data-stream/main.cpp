class MedianFinder {
    multiset<int> left, right;

   public:
    void addNum(int num) {
        left.insert(num);

        right.insert(*left.rbegin());
        left.erase(--left.end());

        if (left.size() >= right.size()) return;

        left.insert(*right.begin());
        right.erase(right.begin());
    }

    double findMedian() {
        double result = *left.rbegin();
        if (left.size() == right.size()) {
            result = 0.5 * (result + *right.begin());
        }
        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
