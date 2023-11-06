class SeatManager {
    set<int> unreservedSeats;
    int i = 1;
    int n;

   public:
    SeatManager(int n) : n(n) {}

    int reserve() {
        if (unreservedSeats.empty()) {
            return i++;
        }
        auto it = unreservedSeats.begin();
        int result = *it;
        unreservedSeats.erase(it);
        return result;
    }

    void unreserve(int seatNumber) { unreservedSeats.insert(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
