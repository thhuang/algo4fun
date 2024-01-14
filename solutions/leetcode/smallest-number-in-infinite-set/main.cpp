class SmallestInfiniteSet {
    set<int> st;
    int mn = 1;

   public:
    int popSmallest() {
        if (st.empty()) return mn++;
        int v = *st.begin();
        st.erase(st.begin());
        return v;
    }

    void addBack(int num) {
        if (num < mn) st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
