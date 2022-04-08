class KthLargest {
    priority_queue<int, vector<int>, greater<>> q_;
    int k_;

   public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (int v : nums) add(v);
    }

    int add(int val) {
        q_.push(val);
        if (q_.size() > k_) q_.pop();
        return q_.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
