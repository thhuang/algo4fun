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

class MRUQueue {
    int m;
    list<int> data;
    vector<list<int>::iterator> iters;

   public:
    MRUQueue(int n) : m(round(sqrt(n))), data(n), iters((n - 1) / m + 1) {
        for (int i = 0; i < n; ++i) {
            auto it = data.insert(data.end(), i + 1);
            if (i % m == 0) iters[i / m] = it;
        }
    }

    int fetch(int k) {
        --k;

        int i = k / m;
        auto it = iters[i];
        for (int j = k % m; j; --j) ++it;

        data.push_back(*it);
        if (k % m == 0) ++iters[i];
        for (++i; i < iters.size(); ++i) ++iters[i];
        data.erase(it);

        return data.back();
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
