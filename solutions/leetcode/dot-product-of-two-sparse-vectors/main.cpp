class SparseVector {
    unordered_map<int, int> data;

   public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) data[i] = nums[i];
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec) {
        auto *a = &data;
        auto *b = &vec.data;
        if (a->size() > b->size()) swap(a, b);

        int sum = 0;
        for (auto [i, v] : *a) {
            auto it = b->find(i);
            if (it != b->end()) sum += v * it->second;
        }

        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
