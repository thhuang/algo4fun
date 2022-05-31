class MRUQueue {
    vector<int> data;

   public:
    MRUQueue(int n) : data(n) { iota(data.begin(), data.end(), 1); }

    int fetch(int k) {
        int v = data[k - 1];
        data.erase(data.begin() + k - 1);
        data.push_back(v);
        return v;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
