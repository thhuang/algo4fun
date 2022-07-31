class NumArray {
    int n;
    vector<int> tree;

    void modify(int k, int x) {
        k += n;
        tree[k] = x;
        for (k /= 2; k >= 1; k /= 2) {
            tree[k] = tree[k * 2] + tree[k * 2 + 1];
        }
    }

    int sum(int l, int r) {
        l += n, r += n;
        int s = 0;
        while (l <= r) {
            if (l % 2 == 1) s += tree[l++];
            if (r % 2 == 0) s += tree[r--];
            l /= 2, r /= 2;
        }
        return s;
    }

   public:
    NumArray(vector<int>& nums) {
        n = 1;
        while (n < nums.size()) n *= 2;
        tree = vector<int>(n * 2, 0);
        for (int i = 0; i < nums.size(); ++i) modify(i, nums[i]);
    }

    void update(int index, int val) { modify(index, val); }

    int sumRange(int left, int right) { return sum(left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
