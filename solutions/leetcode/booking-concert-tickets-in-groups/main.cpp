class BookMyShow {
    class SegmentTree {
        int n;
        vector<long> max_tree;
        vector<long> sum_tree;

       public:
        SegmentTree(int sz, int val) : n(1) {
            while (n < sz) n <<= 1;

            max_tree = vector<long>(n * 2, 0);
            sum_tree = vector<long>(n * 2, 0);

            for (int i = 0; i < sz; ++i) add(i, val);
        }

        void add(int k, int x) {
            k += n;
            max_tree[k] = sum_tree[k] += x;
            for (k /= 2; k; k /= 2) {
                sum_tree[k] = sum_tree[k * 2] + sum_tree[k * 2 + 1];
                max_tree[k] = max(max_tree[k * 2], max_tree[k * 2 + 1]);
            }
        }

        int firstAvailable(int x) {
            if (x > max_tree[1]) return -1;

            int k = 1;
            while (k < n) {
                if (max_tree[k *= 2] >= x) continue;
                if (max_tree[++k] >= x) continue;
                return -1;
            }

            return k - n;
        }

        long sum(int a, int b) {
            a += n, b += n;
            long s = 0;
            while (a <= b) {
                if (a % 2 == 1) s += sum_tree[a++];
                if (b % 2 == 0) s += sum_tree[b--];
                a /= 2, b /= 2;
            }
            return s;
        }

        int at(int i) { return sum_tree[i + n]; }
    };

    int start_row = 0;
    int row_size;
    SegmentTree tree;

   public:
    BookMyShow(int n, int m) : tree{n, m}, row_size(m) {}

    vector<int> gather(int k, int max_row) {
        int r = tree.firstAvailable(k);
        if (r == -1 || r > max_row) return {};

        vector<int> result = {r, row_size - tree.at(r)};
        tree.add(r, -k);
        if (start_row == r && tree.at(r) == 0) ++start_row;

        return result;
    }

    bool scatter(int k, int max_row) {
        if (tree.sum(start_row, max_row) < k) return false;

        for (int i = start_row; i <= max_row && k; ++i) {
            int v = tree.at(i);
            if (v > k) {
                tree.add(i, -k);
                break;
            }

            tree.add(i, -v);
            k -= v;
            ++start_row;
        }

        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
