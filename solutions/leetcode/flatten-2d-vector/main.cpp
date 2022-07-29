class Vector2D {
    vector<vector<int>>::iterator pr;
    vector<int>::iterator pc;
    vector<vector<int>>::iterator row_end;

    void forward() {
        if (!hasNext()) return;

        ++pc;
        if (pc != pr->end()) return;

        ++pr;
        while (pr != row_end && pr->size() == 0) ++pr;
        if (pr == row_end) return;
        pc = pr->begin();
    }

   public:
    Vector2D(vector<vector<int>>& vec) {
        row_end = vec.end();
        pr = vec.begin();
        while (pr != row_end && pr->size() == 0) ++pr;
        if (pr == row_end) return;
        pc = pr->begin();
    }

    int next() {
        int v = *pc;
        forward();
        return v;
    }

    bool hasNext() { return pr != row_end; }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
