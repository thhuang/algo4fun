class MovingAverage {
    int size;
    deque<int> nums;
    int sum = 0;

   public:
    MovingAverage(int size) : size(size) {}

    double next(int val) {
        sum += val;
        nums.push_back(val);
        if (nums.size() > size) {
            sum -= nums.front();
            nums.pop_front();
        }
        return (double)sum / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
