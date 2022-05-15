class ZigzagIterator {
    vector<vector<vector<int>::iterator>> its;

   public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
        : its({{v1.begin(), v1.end()}, {v2.begin(), v2.end()}}) {
        if (v1.empty()) swap(its[0], its[1]);
    }

    int next() {
        int v = *(its[0][0]++);
        if (its[1][0] != its[1][1]) swap(its[0], its[1]);
        return v;
    }

    bool hasNext() { return its[0][0] != its[0][1]; }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
