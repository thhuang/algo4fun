class SmallestInfiniteSet {
    set<int> mp;
    int mn = 1;

   public:
    int popSmallest() {
        if (mp.empty()) return mn++;
        int v = *mp.begin();
        mp.erase(mp.begin());
        return v;
    }

    void addBack(int num) {
        if (num < mn) mp.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
